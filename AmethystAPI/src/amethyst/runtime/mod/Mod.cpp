#include "Mod.h"
#include <fstream>

Mod::Mod(std::string modName)
{
    this->modName = modName;
    fs::path dllPath = GetTempDll();

    // Loads the mod in a temporary directory so that the original DLL can still be built to
    hModule = LoadLibrary(dllPath.string().c_str());
    if (hModule == NULL) {
        DWORD error = GetLastError();

        switch (error) {
        case 0x5:
            Log::Error("[AmethystRuntime] '{}' does not have the required privileges!", dllPath.string());
            throw std::exception();
        case 0x7e:
            Log::Error("[AmethystRuntime] Failed to find '{}'", dllPath.string());
            throw std::exception();
        default:
            Log::Error("[AmethystRuntime] Failed to load '{}.dll', error code: 0x{:x}", modName, error);
            throw std::exception();
        }
    }

    // Load the metadata
    this->metaData = Mod::GetMetaData(modName);
}

FARPROC Mod::GetFunction(const char* functionName)
{
    return GetProcAddress(hModule, functionName);
}

void Mod::Shutdown()
{
    FreeLibrary(hModule);
}

Mod::MetaData Mod::GetMetaData(std::string modName)
{
    // Ensure the mod exists
    std::string modConfigPath = GetAmethystFolder() + "mods/" + modName + "/" + "mod.json";

    if (!fs::exists(modConfigPath)) {
        Assert("[AmethystRuntime] mod.json could not be found, for {}!", modName);
        throw std::exception();
    }

    // Try to read it to a std::string
    std::ifstream modConfigFile(modConfigPath);
    if (!modConfigFile.is_open()) {
        Assert("[AmethystRuntime] Failed to open mod.json, for {}!", modName);
    }

    // Read into a std::string
    std::stringstream buffer;
    buffer << modConfigFile.rdbuf();
    modConfigFile.close();
    std::string fileContents = buffer.str();

    return Mod::ParseMetaData(modName, fileContents);
}

Mod::MetaData Mod::ParseMetaData(std::string modName, std::string fileContents)
{
    // Parse config.json into json
    json data;

    try {
        data = json::parse(fileContents);
    }
    catch (std::exception e) {
        Assert("[AmethystRuntime] Failed to parse mod.json, for {}\n Error: {}", modName, e.what());
    }

    // Verify all fields are correct in config.json
    if (!data["meta"].is_object()) {
        Assert("[AmethystRuntime] Required field \"meta\" should be of type \"object\" in mod.json, for {}", modName);
    }

    if (!data["meta"]["name"].is_string()) {
        Assert("[AmethystRuntime] Required field \"name\" in \"meta\" should be of type \"string\" in mod.json, for {}", modName);
    }

    std::vector<std::string> authors = {};

    if (data["meta"]["author"].is_string()) {
        authors.push_back(data["meta"]["author"]);
    }
    else if (data["meta"]["author"].is_array()) {
        for (const auto& element : data["meta"]["author"]) {
            if (!element.is_string()) {
                Assert("[AmethystRuntime] Array \"author\" in \"meta\" should only contain fields of type \"string\" in mod.json, for {}", modName);
            }
            else {
                authors.push_back(element);
            }
        }
    }
    else {
        Assert("[AmethystRuntime] Required field \"author\" in \"meta\" should be of type \"string\" | \"string[]\" in mod.json, for {}", modName);
    }

    if (!data["meta"]["version"].is_string()) {
        Assert("[AmethystRuntime] Required field \"version\" in \"meta\" should be of type \"string\" in mod.json, for {}", modName);
    }

    // Set values
    MetaData meta;

    meta.name = data["meta"]["name"];
    meta.author = authors;
    meta.version = data["meta"]["version"];

    return meta;
}

fs::path Mod::GetTempDll()
{
    std::string modShortened = modName;
    size_t atPos = modShortened.find("@");

    if (atPos != std::string::npos) {
        modShortened = modShortened.substr(0, atPos);
    }

    // Ensure temp directory exists
    fs::path tempDir = GetAmethystFolder() + "temp/" + modName + "/";
    if (!fs::exists(tempDir)) fs::create_directories(tempDir);

    fs::path originalDll = GetAmethystFolder() + "mods/" + modName + "/" + modShortened + ".dll";
    if (!fs::exists(originalDll)) {
        Log::Error("[AmethystRuntime] Could not find '{}.dll'", modShortened);
        throw std::exception();
    }

    fs::path tempDll = tempDir.string() + modShortened + ".dll";

    try {
        fs::copy_file(originalDll, tempDll, fs::copy_options::overwrite_existing);
    }
    catch (const std::filesystem::filesystem_error& e) {
        Log::Error("[AmethystRuntime] {} (Error code: {})", e.what(), e.code().value());
        throw std::exception();
    }

    return tempDll;
}