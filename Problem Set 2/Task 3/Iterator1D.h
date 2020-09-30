#pragma once
#include "Iterator.h"


class Iterator1D :
    public Iterator
{
private:


public:
    Iterator1D(const std::string* aArray, const int aLength, int aStart = 0) : Iterator(aLength, aStart) {
        f1DArrayElements = aArray;
    }

    const std::string& operator*() const {
        return f1DArrayElements[fIndex];
    }

    bool operator==(const Iterator& aOther) const {        
        return (fIndex == aOther.getfIndex()) && (f1DArrayElements == aOther.f1DArrayElements);
    }

    Iterator begin() const {
        return Iterator1D(f1DArrayElements, fLength);
    }

    Iterator end() const {
        return Iterator1D(f1DArrayElements, fLength, fLength);
    }
};


