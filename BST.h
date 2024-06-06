// header file for Assignment 3 

#include <iostream>
using namespace std;

class BST
{
private:    
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int n) // constructor so that making anew node for the root case is more concise
		{
			this->val = n;
			this->left = nullptr;
			this->right = nullptr;
		};
    };
    TreeNode* root;
    //TreeNode* create(int x);
    TreeNode* insert(TreeNode* t, int x)
    {
         if(t == nullptr)
        {
            return new TreeNode(x);
        }
        else if(t->val == x)
        {
            cout << "Sorry, " << x << " already exists in this tree." << endl;
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
    void inorder(TreeNode* t)
    {
        if (t != nullptr)
	    {
            inorder(t->left); // traverse left
            cout << t->val << " "; // print current node
            inorder(t->right); // traverse right
	    }
    }
    void preorder(TreeNode* t)
    {
        if(t != nullptr)
        {
            cout << t->val << " "; // print current node
            preorder(t->left); // traverse left
            preorder(t->right); // traverse right
        }
    }
    void postorder(TreeNode* t)
    {
        if(t != nullptr)
        {
            postorder(t->left); // traverse left
            postorder(t->right); // traverse right
            cout << t->val << " "; // print current node
        }
    }
    TreeNode* find(TreeNode* t, int x)
    {
        if((t == nullptr) || (t->val == x))
        {
            return t;
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
    TreeNode* findPredecessor(TreeNode* t, int x)
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
        return t;
    }
    TreeNode* findSuccessor(TreeNode* t, int x)
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
        return t;
    }
    int treeHeight(TreeNode* t)
    {
        if(t == nullptr)
        {
            return -1;
        }
        else
        {
            int leftHeight = treeHeight(t->left); // left tree height
            int rightHeight = treeHeight(t->right); // right tree height

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
    int totalNodes(TreeNode* t)
    {
        return (totalNodes(t->left) + totalNodes(t->right));
    }
    TreeNode* remove(TreeNode* &t, int x)
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
                TreeNode* temp = t->right;
                free(t);
                return temp;
            }
            else if(t->right == nullptr) // 1 child case
            {
                TreeNode* temp = t->left;
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
    }
    bool balanced(TreeNode* t);
    void destroy(TreeNode* t);

 public:
    BST()
    {
        root = nullptr;
    }
    void insertNode(int x)
    {
        root = insert(root, x);
    }
    void inorderDisplay()
	{
		inorder(root);
	}
	void preorderDisplay()
	{
		preorder(root);
	}
	void postorderDisplay()
	{
		postorder(root);
	}
    int findNode(int x)
    {
        if(find(root, x))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    TreeNode* predecessor(int x)
    {
        return findPredecessor(root, x);
    }
    TreeNode* successor(int x)
    {
        return findSuccessor(root, x);
    }
    int height()
    {
        return treeHeight(root);
    }
    int nodeCount()
    {
        return totalNodes(root);
    }
    void deleteNode(int x)
    {
        remove(root, x);
    }
    bool isBalanced()
    {
        return balanced(root);
    }
    TreeNode* destroyTree()
    {
        destroy(root);
        return nullptr;
    }
};