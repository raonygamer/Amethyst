#include "mc/src/common/world/item/Item.hpp"

short Item::getDamageValue(const CompoundTag* userData) const
{
    if (userData == nullptr) return 0;
    if (!userData->contains("Damage")) return 0;
    return (short)userData->getInt("Damage");
}

CreativeItemCategory Item::getCreativeCategory() const {
    return mCreativeCategory;
}

const std::string& Item::getCreativeGroup() const {
    return mCreativeGroup;
}

int Item::getFrameCount() const {
    return mFrameCount;
}

const std::string& Item::getFullItemName() const {
    return mFullName.getString();
}

const HashedString& Item::getFullNameHash() const {
    return mFullName;
}

float Item::getFurnaceBurnIntervalMultipler() const {
    return mFurnaceBurnIntervalModifier;
}

std::string Item::getHoverTextColor(const ItemStackBase& stack) const {
    return mHoverTextColorFormat; 
}

short Item::getId() const {
    return mId;
}

const WeakPtr<const BlockLegacy>& Item::getLegacyBlock() const {
    return reinterpret_cast<const WeakPtr<const BlockLegacy>&>(mLegacyBlock);
}

Interactions::Mining::MineBlockItemEffectType Item::getMineBlockType() const {
    return mMineBlockType;
}

const std::string& Item::getNamespace() const {
    return mNamespace;
}

const HashedString& Item::getRawNameHash() const {
    return mRawNameId;
}

const std::string& Item::getRawNameId() const {
    return mRawNameId.getString();
}

const BaseGameVersion& Item::getRequiredBaseGameVersion() const {
    return mMinRequiredBaseGameVersion;
}

UseAnim Item::getUseAnimation() const {
    return mUseAnim;
}

void Item::setDamageValue(ItemStackBase& stack, short value) const {
    if (stack.mUserData == nullptr) {
        stack.setUserData(std::make_unique<CompoundTag>());
    }
    if (stack.mUserData->contains("Damage"))
        stack.mUserData->getIntTag("Damage")->data = value;
    stack.mUserData->put("Damage", IntTag(value));
}

Item& Item::setAllowOffhand(bool allowOffhand) {
    mAllowOffhand = allowOffhand;
    return *this;
}

Item& Item::setCreativeGroup(const std::string& group) {
    mCreativeGroup = group;
    return *this;
}

Item& Item::setExplodable(bool isExplodable) {
    mExplodable = isExplodable;
    return *this;
}

Item& Item::setFireResistant(bool isFireResistant) {
    mFireResistant = isFireResistant;
    return *this;
}

Item& Item::setFurnaceBurnIntervalMultiplier(float multiplier) {
    mFurnaceBurnIntervalModifier = multiplier;
    return *this;
}

Item& Item::setFurnaceXPmultiplier(float multiplier) {
    mFurnaceXPmultiplier = multiplier;
    return *this;
}

Item& Item::setHandEquipped() {
    mHandEquipped = true;
    return *this;
}

Item& Item::setHoverTextColorFormat(std::string_view format) {
    mHoverTextColorFormat = format;
    return *this;
}

Item& Item::setIsGlint(bool isGlint) {
    mIsGlint = isGlint;
    return *this;
}

Item& Item::setIsHiddenInCommands(ItemCommandVisibility visibility) {
    // Assuming ItemCommandVisibility is enum, e.g., Visible / Hidden
    mIsHiddenInCommands = (visibility == ItemCommandVisibility::Hidden);
    return *this;
}

Item& Item::setIsMirroredArt(bool isMirroredArt) {
    mIsMirroredArt = isMirroredArt;
    return *this;
}

Item& Item::setMaxStackSize(uint8_t maxStackSize) {
    if (maxStackSize == 0) Log::Warning("Setting max stack size to 0 will cause crashes!");
    if (maxStackSize > 64) Log::Info("Setting max stack size over 64 will cause weird bugs");

    mMaxStackSize = maxStackSize;
    return *this;
}

Item& Item::setMinRequiredBaseGameVersion(const BaseGameVersion& version) {
    mMinRequiredBaseGameVersion = version;
    return *this;
}

Item& Item::setRequiresWorldBuilder(bool requiresWorldBuilder) {
    mRequiresWorldBuilder = requiresWorldBuilder;
    return *this;
}

Item& Item::setShouldDespawn(bool shouldDespawn) {
    mShouldDespawn = shouldDespawn;
    return *this;
}

Item& Item::setStackedByData(bool stackedByData) {
    mIsStackedByData = stackedByData;
    return *this;
}

Item& Item::addTag(const ItemTag& tag) {
    mTags.push_back(tag);
    return *this;
}

Item& Item::addTag(const HashedString& tag) {
    mTags.emplace_back(tag);
    return *this;
}

Item& Item::addTags(std::initializer_list<std::reference_wrapper<const ItemTag>> tags) {
    for (const ItemTag& tag : tags) {
        mTags.push_back(tag);
    }
    return *this;
}

Item& Item::setUseAnimation(UseAnim useAnim) {
    mUseAnim = useAnim;
    return *this;
}

bool Item::hasTag(const ItemTag& tag) const {
    for (const auto& t : mTags) {
        if (t == tag) return true;
    }
    return false;
}

bool Item::hasTag(const HashedString& tag) const {
    for (const auto& t : mTags) {
        if (t.getHash() == tag.getHash()) return true; // Assuming ItemTag can provide HashedString hash
    }
    return false;
}

bool Item::isAnimatedInToolbar() const {
    return mAnimatesInToolbar;
}

bool Item::isCamera() const {
    return mCameraComponentLegacy != nullptr;
}

bool Item::isExplodable() const {
    return mExplodable;
}

bool Item::isFireResistant() const {
    return mFireResistant;
}

bool Item::isMirroredArt() const {
    return mIsMirroredArt;
}

bool Item::isSeed() const {
    return mSeedComponent != nullptr;
}

bool Item::shouldDespawn() const {
    return mShouldDespawn;
}

bool Item::allowOffhand() const {
    return mAllowOffhand;
}

void Item::clearTags() {
    mTags.clear();
}