#pragma once
#include "TreeNode.h"
#include <iostream>
using namespace std;

template <class DataType>
class Tree
{
public:

    // Function to insert nodes in level order 
    TreeNode<DataType>* insertLevelOrder(DataType arr[], TreeNode<DataType>* root,
        int i, int n, TreeNode<DataType>* parent)
    {
        // Base case for recursion 
        if (i < n)
        {
            TreeNode<DataType>* node = new TreeNode<DataType>();
            node->data = arr[i];
            node->left = node->right = NULL;
            root = node;
           
            root->parent = parent;

            // insert left child 
            root->left = insertLevelOrder(arr,
                root->left, 2 * i + 1, n, root);

            // insert right child 
            root->right = insertLevelOrder(arr,
                root->right, 2 * i + 2, n, root);
        }
        return root;
    }

    // Function to print tree nodes in 
// InOrder fashion 
    void inOrder(TreeNode<DataType>* root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            inOrder(root->left);
            inOrder(root->right);
        }
    }
};

