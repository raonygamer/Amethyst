#include <mc/src/common/world/actor/player/Player.hpp>
#include <mc/src/common/world/actor/player/PlayerInventory.hpp>
#include <mc/src/common/world/inventory/transaction/ComplexInventoryTransaction.hpp>
#include <mc/src/common/world/entity/components/AbilitiesComponent.hpp>
#include <mc/src/common/world/entity/components/UserEntityIdentifierComponent.hpp>
#include "Player.hpp"

const PlayerInventory& Player::getSupplies() const
{
    return *this->playerInventory;
}

PlayerInventory& Player::getSupplies()
{
    return *this->playerInventory;
}

const ItemStack& Player::getSelectedItem() const
{
    return playerInventory->getSelectedItem();
}

 PlayerEventCoordinator& Player::getPlayerEventCoordinator() {
     using function = decltype(&Player::getPlayerEventCoordinator);
     uintptr_t** vtable = *(uintptr_t***)this;
     auto func = std::bit_cast<function>(vtable[244]);
     return (this->*func)();
 }

 void Player::sendInventoryTransaction(const InventoryTransaction& transaction)
 {
     using function = decltype(&Player::sendInventoryTransaction);
     uintptr_t** vtable = *(uintptr_t***)this;
     auto func = std::bit_cast<function>(vtable[241]);
     return (this->*func)(transaction);
 }

 void Player::sendComplexInventoryTransaction(std::unique_ptr<ComplexInventoryTransaction> transaction) const
 {
     using function = decltype(&Player::sendComplexInventoryTransaction);
     uintptr_t** vtable = *(uintptr_t***)this;
     auto func = std::bit_cast<function>(vtable[242]);
     return (this->*func)(std::move(transaction));
 }

void Player::sendNetworkPacket(Packet& packet)
{
    using function = decltype(&Player::sendNetworkPacket);
    uintptr_t** vtable = *(uintptr_t***)this;
    auto func = std::bit_cast<function>(vtable[243]);
    return (this->*func)(packet);
}

const LayeredAbilities& Player::getAbilities() const
{
    return this->tryGetComponent<AbilitiesComponent>()->mAbilities;
}

GameMode& Player::getGameMode() const
{
    return *this->mGameMode.get();
}

bool Player::canUseOperatorBlocks() const
{
    const LayeredAbilities& abilities = this->getAbilities();
    if (!abilities.getBool(11)) return false;
    return abilities.getBool(6);
}

void Player::updateSkin(const SerializedSkin& skin, int clientSubID) {
    using function = decltype(&Player::updateSkin);
    static auto func = std::bit_cast<function>(SigScan("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 41 8B D8 4C 8B FA"));
    return (this->*func)(skin, clientSubID);
}

void Player::setPlayerGameType(GameType gameType)
{
    using function = decltype(&Player::setPlayerGameType);
    uintptr_t** vtable = *(uintptr_t***)this;
    auto func = std::bit_cast<function>(vtable[226]);
    return (this->*func)(gameType);
}

void Player::setContainerManagerModel(std::shared_ptr<IContainerManager> manager)
{
    mContainerManager = manager;
}

std::weak_ptr<IContainerManager> Player::getContainerManagerModel() const
{
    return mContainerManager;
}

const ServerPlayer* Player::getServerPlayer() const
{
    if (isClientSide()) 
        return nullptr;
    return reinterpret_cast<const ServerPlayer*>(this);
}

const LocalPlayer* Player::getLocalPlayer() const
{
    if (!isClientSide()) 
        return nullptr;
    return reinterpret_cast<const LocalPlayer*>(this);
}

ServerPlayer* Player::getServerPlayer()
{
    if (isClientSide())
        return nullptr;
    return reinterpret_cast<ServerPlayer*>(this);
}

LocalPlayer* Player::getLocalPlayer()
{
    if (!isClientSide())
        return nullptr;
    return reinterpret_cast<LocalPlayer*>(this);
}

SerializedSkin& Player::getSkin()
{
    return mSkin;
}

const SerializedSkin& Player::getSkin() const
{
    return mSkin;
}

UserEntityIdentifierComponent* Player::getUserIdentity() {
    return tryGetComponent<UserEntityIdentifierComponent>();
}

const UserEntityIdentifierComponent* Player::getUserIdentity() const {
	return tryGetComponent<UserEntityIdentifierComponent>();
}