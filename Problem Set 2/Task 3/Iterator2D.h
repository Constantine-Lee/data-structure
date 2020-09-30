#pragma once
#include "Iterator.h"

class Iterator2D :
    public Iterator
{
private:


public:
    Iterator2D(const std::string** aArray, const int aLength, int aStart = 0) : Iterator(aLength, aStart) {
        f2DArrayElements = aArray;
    }

    const std::string& operator*() const {
        return f2DArrayElements[fIndex / 4][fIndex % 4];
    }

    bool operator==(const Iterator& aOther) const {
        return (fIndex == aOther.getfIndex()) && (f2DArrayElements == aOther.f2DArrayElements);
    }

    Iterator begin() const {
        return Iterator2D(f2DArrayElements, fLength);
    }

    Iterator end() const {
        return Iterator2D(f2DArrayElements, fLength, fLength);
    }
};



