#pragma once

template <class DataType>
class StackNode
{
public:
	DataType data;
	StackNode<DataType>* next;

	StackNode() {};
};

