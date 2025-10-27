#include "mc/src-deps/core/container/Blob.hpp"

namespace mce {
    Blob::Blob() 
        : mBlob(nullptr, Deleter()), mSize(0) 
    {}

    Blob::Blob(const iterator data, const size_type size)
        : mBlob(new value_type[size], Deleter(defaultDeleter)), mSize(size)
    {
        std::copy(data, data + size, mBlob.get());
    }

	Blob::Blob(size_type size) 
		: mBlob(new value_type[size], Deleter(defaultDeleter)), mSize(size)
	{}

    Blob::Blob(const Blob& other)
        : mSize(other.mSize),
          mBlob(nullptr, Deleter(other.mBlob.get_deleter().getDeleteFunc()))
    {
        if (other.mBlob && other.mSize > 0) {
            value_type* newData = new value_type[other.mSize];
            std::copy(other.mBlob.get(), other.mBlob.get() + other.mSize, newData);
            mBlob.reset(newData);
        }
    }

    Blob::Blob(Blob&& other) noexcept
        : mBlob(std::move(other.mBlob)), mSize(other.mSize)
    {
        other.mSize = 0;
    }

    Blob& Blob::operator=(const Blob& other) {
        if (this != &other) {
            value_type* newData = nullptr;
            if (other.mSize > 0) {
                newData = new value_type[other.mSize];
                std::copy(other.mBlob.get(), other.mBlob.get() + other.mSize, newData);
            }

            Deleter newDeleter(other.mBlob.get_deleter().getDeleteFunc());
            pointer_type newBlob(newData, newDeleter);

            mBlob.swap(newBlob);
            mSize = other.mSize;
        }
        return *this;
    }

    Blob& Blob::operator=(Blob&& other) noexcept {
        if (this != &other) {
            mBlob = std::move(other.mBlob);
            mSize = other.mSize;
            other.mSize = 0;
        }
        return *this;
    }

    Blob::size_type Blob::size() const noexcept {
        return mSize;
    }

    Blob::iterator Blob::data() noexcept {
        return mBlob.get();
    }

    const Blob::iterator Blob::data() const noexcept {
        return mBlob.get();
    }

    bool Blob::empty() const noexcept {
        return mSize == 0;
    }

    void Blob::swap(Blob& other) noexcept {
        std::swap(mBlob, other.mBlob);
        std::swap(mSize, other.mSize);
    }

    void Blob::resize(size_type newSize) {
        pointer_type newBlob(new value_type[newSize], mBlob.get_deleter());
        std::copy(mBlob.get(), mBlob.get() + std::min(mSize, newSize), newBlob.get());
        mBlob.swap(newBlob);
        mSize = newSize;
    }

    bool Blob::operator==(const Blob& other) const noexcept {
        return mSize == other.mSize &&
               std::equal(mBlob.get(), mBlob.get() + mSize, other.mBlob.get());
    }

    void Blob::defaultDeleter(iterator data) {
        delete[] data;
    }

} // namespace mce
