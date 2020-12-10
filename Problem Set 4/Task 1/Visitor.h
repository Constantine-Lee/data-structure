#pragma once
class Room;
template <class DataType>
class TreeNode;

class Visitor
{
public:
	virtual void visitDungeonRoom(TreeNode<Room>* node) = 0;
};

