/// @symbolgeneration
#pragma once
#include "amethyst/Imports.hpp"
#include "mc/src/common/config/ScreenCapabilities.hpp"
#include "mc/src-client/common/client/game/MinecraftGame.hpp"
#include "mc/src-client/common/client/game/ClientInstance.hpp"
#include "mc/src/common/network/DisconnectFailReason.hpp"
#include "mc/src-client/common/client/services/download/IDlcBatcher.hpp"

class SceneStack;
class IAdvancedGraphicsOptions;
class SceneFactory;
class Player;
class ItemGroup;
class DlcId;

/// @vptr {0x4D01468}
class MinecraftScreenModel : public IDlcBatcher, public std::enable_shared_from_this<MinecraftScreenModel> {
public:
    class Context {
    public:
        MinecraftGame& mMinecraft;
        ClientInstance& mClient;
        Bedrock::NotNullNonOwnerPtr<IAdvancedGraphicsOptions> mAdvancedGraphicsOptions;
        Bedrock::NotNullNonOwnerPtr<SceneStack> mSceneStack;
        SceneFactory& mSceneFactory;
        std::unique_ptr<IScreenCapabilities> mCapabilities;
    };

    MC static uintptr_t $vtable_for_this;
    std::byte padding24[0xE8 - 0x10 - 0x8]; // full_size - shared_from_this - vptr

    /// @signature {48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 4C 8B F2 48 8B F1 48 89 4D ? 48 89 55 ? 33 D2}
    MC MinecraftScreenModel(const MinecraftScreenModel::Context& context);

    /// @vidx {0}
    MC virtual ~MinecraftScreenModel();

    /// @vidx {1}
	MC virtual IDlcBatchModel& getDlcBatchModel(const std::vector<DlcId>& unk0);

	/// @vidx {2}
	MC virtual IDlcBatchModel& getDlcBatchModel(const std::vector<std::string>& unk0);

	/// @vidx {3}
	MC virtual IDlcBatchModel& getDlcBatchModel(const std::vector<PackIdVersion>& unk0);

	/// @vidx {4}
	MC virtual void navigateToDisconnectScreen(const std::string& unk0, const std::string& unk1, Connection::DisconnectFailReason unk2);

	/// @vidx {5}
	MC virtual bool isInGame() const;

	/// @vidx {6}
	MC virtual bool isSelectedSkinInitialized() const;

	/// @vidx {7}
	MC virtual UnknownReturn platformTTSExists() const;

	/// @vidx {8}
	MC virtual UnknownReturn getStoreCatalogRepository() const;

	/// @vidx {9}
	MC virtual UnknownReturn getStoreNetworkFailureTimeout() const;

	/// @vidx {10}
	MC virtual bool isAdhocEnabled() const;

	/// @vidx {11}
	MC virtual bool isDirty() const;

	/// @vidx {12}
	MC virtual UnknownReturn getSelectedSkinHandle() const;

	/// @vidx {13}
	MC virtual std::string getLastPoppedScreenName() const;

    /// @signature {48 89 5C 24 ? 57 48 83 EC ? 48 8B D1 48 8B 41 ? 48 85 C0 74 ? 48 83 38 ? 74 ? 48 8B 41 ? 48 85 C0 74 ? F0 FF 40 ? 48 8B 49 ? 48 89 4C 24 ? 48 8B 5A ? 48 89 5C 24 ? 48 8B 09 48 8B 01 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 48 8B F8 48 85 DB 74 ? 48 8B CB E8 ? ? ? ? 48 8B C7 48 8B 5C 24 ? 48 83 C4 ? 5F C3 E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 48 89 5C 24 ? 57 48 83 EC ? 48 8B D1 48 8B 41 ? 48 85 C0 74 ? 48 83 38 ? 74 ? 48 8B 41 ? 48 85 C0 74 ? F0 FF 40 ? 48 8B 49 ? 48 89 4C 24 ? 48 8B 5A ? 48 89 5C 24 ? 48 8B 09 48 8B 01 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 48 8D B8}
    MC Player* getPlayer();

    /// @signature {48 89 5C 24 ? 57 48 83 EC ? 48 8B D1 48 8B 41 ? 48 85 C0 74 ? 48 83 38 ? 74 ? 48 8B 41 ? 48 85 C0 74 ? F0 FF 40 ? 48 8B 49 ? 48 89 4C 24 ? 48 8B 5A ? 48 89 5C 24 ? 48 8B 09 48 8B 01 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 48 8D B8 ? ? ? ? 48 85 DB 74 ? 48 8B CB E8 ? ? ? ? 48 8B C7 48 8B 5C 24 ? 48 83 C4 ? 5F C3 E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 74 24}
    MC const ItemGroup& getCursorSelectedItemGroup() const;
};

static_assert(sizeof(MinecraftScreenModel) == 0xE8);