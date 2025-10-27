#pragma once
#include <cstdint>
#include <variant>
#include <mc/src/common/world/inventory/network/TypedServerNetId.hpp>
#include <mc/src/common/world/inventory/network/TypedClientNetId.hpp>

struct ItemStackNetIdTag {};
struct ItemStackRequestIdTag {};
struct ItemStackLegacyRequestIdTag {};

class ItemStackNetIdVariant {
public:
	using ServerId = TypedServerNetId<ItemStackNetIdTag, int, 0>;
    using RequestId = TypedClientNetId<ItemStackRequestIdTag, int, 0>;
    using LegacyRequestId = TypedClientNetId<ItemStackLegacyRequestIdTag, int, 0>;

	std::variant<ServerId, RequestId, LegacyRequestId> mVariant;

public:
    ItemStackNetIdVariant() 
		: mVariant(ServerId(0)) {}
};

static_assert(sizeof(ItemStackNetIdVariant) == 24);