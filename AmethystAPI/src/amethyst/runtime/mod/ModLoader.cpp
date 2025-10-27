#include "amethyst/runtime/AmethystContext.hpp"
#include "amethyst/runtime/mod/ModLoader.hpp"

namespace Amethyst {
ModLoader::ModLoader(AmethystContext* ctx) :
    mContext(ctx)
{
}

ModLoader::~ModLoader()
{
    UnloadAll();
    for (const auto& error : GetErrors()) {
        Log::Error("{}", error.toString());
    }
}

void ModLoader::LoadGraph(const ModGraph& graph)
{
    UnloadAll();
    for (const auto& modInfo : graph.GetMods()) {
        auto mod = LoadSingle(modInfo);
        if (mod.expired()) {
            ModError error;
            error.Step = ModErrorStep::Loading;
            error.Type = ModErrorType::Unknown;
            error.UUID = modInfo->UUID;
            error.Message = "Failed to load mod: '{mod}'";
            error.Data["{mod}"] = modInfo->GetVersionedName();
            mErrors.push_back(error);
        }
        else {
            Log::Info("Loaded mod: '{}'", modInfo->GetVersionedName());
        }
    }

    for (const auto& mod : mMods) {
        auto error = mod->CallInitialize(*mContext);
        if (error.has_value()) {
            mErrors.push_back(*error);
        }
        else {
            Log::Info("Initialized mod: '{}'", mod->mInfo->GetVersionedName());
        }
	}
}

std::weak_ptr<const Mod> ModLoader::LoadSingle(const std::shared_ptr<const ModInfo>& info)
{
    auto mod = std::make_shared<Mod>(info);
    auto error = mod->Load();
    if (error.has_value()) {
        mErrors.push_back(*error);
        return {};
    }
    mMods.emplace_back(mod);
    return mod;
}

void ModLoader::UnloadAll()
{
    mErrors.clear();
    for (auto it = mMods.rbegin(); it != mMods.rend(); ++it) {
        Unload((*it)->mInfo);
    }
}

void ModLoader::Unload(const std::shared_ptr<const ModInfo>& info)
{
    Unload(info->UUID);
}

void ModLoader::Unload(const std::string& uuid)
{
    auto it = std::find_if(mMods.begin(), mMods.end(), [&uuid](const std::shared_ptr<Mod>& mod) {
        return mod->mInfo->UUID == uuid;
    });
    if (it != mMods.end()) {
        auto& mod = *it;
        mod->Unload();
        mMods.erase(it);
    }
}

std::weak_ptr<const Mod> ModLoader::GetModByUUID(const std::string& uuid) const
{
    auto it = std::find_if(mMods.begin(), mMods.end(), [&uuid](const std::shared_ptr<Mod>& mod) {
        return mod->mInfo->UUID == uuid;
    });
    if (it != mMods.end()) {
        return *it;
    }
    return {};
}

std::weak_ptr<const Mod> ModLoader::GetModByNamespace(const std::string& modNamespace) const
{
    auto it = std::find_if(mMods.begin(), mMods.end(), [&modNamespace](const std::shared_ptr<Mod>& mod) {
        return mod->mInfo->Namespace == modNamespace;
    });
    if (it != mMods.end()) {
        return *it;
    }
    return {};
}

std::vector<std::weak_ptr<const Mod>> ModLoader::GetMods() const
{
    std::vector<std::weak_ptr<const Mod>> mModsWeak;
    mModsWeak.reserve(mMods.size());
    std::transform(
        mMods.begin(), mMods.end(),
        std::back_inserter(mModsWeak),
        [](const std::shared_ptr<const Mod>& sp) {
            return std::weak_ptr<const Mod>(sp);
        }
    );
    return mModsWeak;
}

size_t ModLoader::GetModCount() const
{
    return mMods.size();
}

const std::vector<ModError>& ModLoader::GetErrors() const
{
    return mErrors;
}

bool ModLoader::HasErrors() const
{
    return !mErrors.empty();
}
} // namespace Amethyst