#pragma once
#include <functional>
#include <cstdint>

struct ActorUniqueID {
    int64_t rawID;

    ActorUniqueID() : rawID(-1) {}
    ActorUniqueID(int64_t id) : rawID(id) {}
	ActorUniqueID(const ActorUniqueID& other) : rawID(other.rawID) {}

    bool operator==(const ActorUniqueID& other) const
    {
        return rawID == other.rawID;
    }
};

namespace std {
template <>
struct hash<ActorUniqueID> {
    size_t operator()(const ActorUniqueID& id) const noexcept
    {
        return std::hash<int64_t>{}(id.rawID);
    }
};
}