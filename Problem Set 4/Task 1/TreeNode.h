#pragma once
#include <stdio.h>
#include "Visitor.h"

template <class DataType>
class TreeNode
{
public:
	DataType data;
	TreeNode* left;
	TreeNode* right;

	void acceptVisitor(Visitor* visitor) {
		visitor->visitDungeonRoom(this);
	}
};
