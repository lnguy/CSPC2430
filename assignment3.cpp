#include "BST.h"
#include <iostream>

int main() 
{
	BST t;
	t.insertNode (10);
	t.insertNode (7);
	t.insertNode (29);
	t.insertNode (29);
	t.insertNode (30);
	t.insertNode (9);
	//cout << t.findNode(18);
	cout << t.predecessor(10);
	// inorder display
	//t.inorderDisplay();  // the output should be: 7, 9, 10, 29, 30
	//cout << endl;
	// preorder display
	//t.preorderDisplay();  // the output should be: 10, 7, 9, 29, 30
	//cout << endl;
	// postorder display
	//t.postorderDisplay();  // the output should be: 9, 7, 30, 29, 10
	return 0; 
}