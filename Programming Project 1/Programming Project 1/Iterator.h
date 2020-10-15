#pragma once

#include <iostream>

using namespace std;

class Iterator
{
public:
	const int fLength;
	int fIndex;
	const string* arr;

	Iterator(const std::string* aArray, const int aLength, int aStart = 0) : arr(aArray), fLength(aLength), fIndex(aStart) {

	}

	int getfIndex() const { return fIndex; }

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

    const std::string& operator*() const {
        return arr[fIndex];
    }

    bool operator==(const Iterator& aOther) const {
        return (fIndex == aOther.getfIndex()) && (arr == aOther.arr);
    }

    Iterator begin() const {
        return Iterator(arr, fLength);
    }

    Iterator end() const {
        return Iterator(arr, fLength, fLength);
    }
};

