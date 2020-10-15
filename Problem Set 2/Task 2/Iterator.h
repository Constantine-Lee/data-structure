#pragma once
#include <string>
#include <iostream>

class Iterator
{
protected:
	const int fLength;
	int fIndex;

public:
	Iterator(const int aLength, int aStart) : fLength(aLength), fIndex(aStart) {
	}

    const std::string* f1DArrayElements;
    const std::string** f2DArrayElements;

    int getfIndex() const { return fIndex; }

    virtual const std::string& operator*() const { return ""; }

    Iterator& operator++() {
        fIndex++;
        return *this;
    }
    Iterator operator++(int) {
        Iterator temp = *this;
        fIndex++;
        return temp;
    }
    Iterator& operator--() {
        fIndex--;
        return *this;
    }
    Iterator operator--(int) {
        Iterator temp = *this;
        fIndex--;
        return temp;
    }
    virtual bool operator==(const Iterator& aOther) const { return false; };
    virtual Iterator begin() const { return *this; }
    virtual Iterator end() const { return *this; }
};

