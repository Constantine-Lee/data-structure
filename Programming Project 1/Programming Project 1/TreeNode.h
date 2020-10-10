#pragma once
#include <stdio.h>

template <class DataType>
class TreeNode
{
public:
	DataType data;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;    

};

