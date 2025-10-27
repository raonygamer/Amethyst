/// @symbolgeneration
#pragma once
#include "amethyst/Imports.hpp"
#include "mc/src/common/world/containers/managers/IContainerManager.hpp"
#include "mc/src/common/world/inventory/network/ContainerScreenContext.hpp"
#include "mc/src/common/world/containers/models/ContainerModel.hpp"

class ContainerManagerController;

/// @vptr {0x4DE9970}
class ContainerManagerModel :
	public IContainerManager
{
public:
    Player& mPlayer;
    std::vector<ItemStack> mLastSlots;
    ContainerID mContainerId;
    ContainerType mContainerType;
    std::unordered_map<const ContainerManagerController*, std::function<void(ContainerManagerModel&)>> mInformControllerOfDestructionCallbacks;
    ContainerScreenContext mScreenContext;
    std::unordered_map<std::string, std::shared_ptr<ContainerModel>> mContainers;

    /// @signature {48 89 5C 24 ? 48 89 4C 24 ? 57 48 83 EC ? 48 8B D9 48 8D 05 ? ? ? ? 48 89 01 4C 89 41}
    MC ContainerManagerModel(ContainerID id, Player& player);

    /// @vidx {0}
    MC virtual ~ContainerManagerModel();
    /// @vidx {1}
    MC virtual ContainerID getContainerId();
    /// @vidx {2}
    MC virtual void setContainerId(ContainerID id);
    /// @vidx {3}
    MC virtual ContainerType getContainerType();
    /// @vidx {4}
    MC virtual void setContainerType(ContainerType type);
    /// @vidx {5}
    MC virtual void serverInitItemStackIds();
    /// @vidx {6}
    MC virtual std::vector<ItemStack> getItemCopies() const = 0;
    /// @vidx {7}
    MC virtual void setSlot(int slot, const ItemStack& stack, bool) = 0;
    /// @vidx {8}
    MC virtual const ItemStack& getSlot(int slot) const = 0;
    /// @vidx {9}
    MC virtual void setData(int, int) = 0;
    /// @vidx {10}
    MC virtual void broadcastChanges() = 0;
    /// @vidx {11}
    MC virtual void debitPlayerLevels(int amount);
    /// @vidx {12}
    MC virtual bool isCreativeMode();
    /// @vidx {13}
    MC virtual bool isClientSide();
    /// @vidx {14}
    MC virtual bool isServerAuthoritative();
    /// @vidx {15}
    MC virtual bool isValid(float);
    /// @vidx {16}
    MC virtual int tick();
    /// @vidx {17}
    MC virtual ContainerScreenContext _postInit() = 0;

// Non-virtuals
public:

    /// @signature {48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 4C 8B E9}
    MC void postInit();

    void _addContainer(std::shared_ptr<ContainerModel> model) {
        mContainers[model->mContainerStringName] = model;
    }

    ContainerModel* getContainerByName(const std::string& name) {
        auto it = mContainers.find(name);
        if (it != mContainers.end()) {
            return it->second.get();
        }
        return nullptr;
    }
};

static_assert(sizeof(ContainerManagerModel) == 0xD8);
static_assert(offsetof(ContainerManagerModel, mScreenContext) == 112);