/* #include "BST.h"
#include <iostream>
using namespace std;

BST::TreeNode* insert(TreeNode* t, int x)
{
    if(t == nullptr)
    {
        return new TreeNode(x);
    }
     else if(t->val == x)
    {
        
    }
    else if(t->val > x) // left child case
	{
		t->left = insert(t->left, x);
	}
	else if(t->val < x) // right child case
	{
		t->right = insert(t->right, x);
	}
	return t;
}

BST::inorder(TreeNode* t)
{
    if (t != nullptr)
	{
		inorder(t->left); // traverse left
		cout << t->val << " "; // print current node
		inorder(t->right); // traverse right
	}
}

BST::preorder(TreeNode* t)
{
    if(t != nullptr)
	{
		cout << t->val << " "; // print current node
    	preorder(t->left); // traverse left
		preorder(t->right); // traverse right
	}
}

BST::postorder(TreeNode* t)
{
    if(t != nullptr)
	{
		postorder(t->left); // traverse left
		postorder(t->right); // traverse right
		cout << t->val << " "; // print current node
	}
}

BST::find(TreeNode* t, int x)
{
    if(t == nullptr)
    {
        return false;
    }
    else if (t->val == x)
    {
        return true;
    }
    else if(t->val > x)
    {
        find(t->left, x);
    }
    else if(t->val < x)
    {
        find(t->right, x);
    }
    return t;
}

BST::findPredecessor(TreeNode* t, int x)
{
    if(t == nullptr)
    {
        return nullptr;
    }
    else if(t->val == x)
    {
        TreeNode* temp = t->left;
        while(temp->right != nullptr) // loop through left tree to find greatest value
        {
            temp = temp->left;
        }
        return temp;
    }
    else if(t->val > x)
    {
        find(t->left, x);
    }
    else if(t->val < x)
    {
        find(t->right, x);
    }
}

BST::findSuccessor(TreeNode* t, int x)
{
    if(t == nullptr)
    {
        return nullptr;
    }
    else if(t->val == x)
    {
        TreeNode* temp = t->right;
        while(temp->left != nullptr) // loop through right tree to find smallest value
        {
            temp = temp->right;
        }
        return temp;
    }
    else if(t->val > x)
    {
        find(t->left, x);
    }
    else if(t->val < x)
    {
        find(t->right, x);
    }
}

BST::treeHeight(TreeNode* t)
{
    if(t == nullptr)
    {
        return -1;
    }
    else
    {
        int leftHeight = treeHeight(node->left); // left tree height
        int rightHeight = treeHeight(node->right); // right tree height

        if(leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

BST::totalNodes(TreeNode* t)
{
    return (totalNodes(node->left) + totalNodes(node->right));
}

BST::remove(TreeNode* &t, int x)
{
    if(t == nullptr)
    {
        return t;
    }
    else if(t->val > x)
    {
        t->left = remove(t->left, x);
    }
    else if(t->val < x)
    {
        t->right = remove(t->right, x);
    }
    else // t->val == x
    {
        if((t->left == nullptr) && (t->right == nullptr)) // 0 children case
        {
            return nullptr;
        }
        else if(t->left == nullptr) // 1 child case
        {
            new TreeNode* temp = t->right;
            free(t);
            return temp;
        }
        else if(t->right == nullptr) // 1 child case
        {
            new TreeNode* temp = t->left;
            free(t);
            return temp;
        }
        else if((t->left != nullptr) && (t->right == nullptr)) // predecessor case
        {

        }
        else if((t->left == nullptr) && (t->right != nullptr)) // successor case
        {

        }
    }
    
} */