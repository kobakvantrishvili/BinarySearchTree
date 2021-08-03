#pragma once
#include "TreeNode.h"
#ifndef BST
#define BST

using namespace std;

class BSTree {
public:

	//Constructor
	BSTree();
	//Copy Constructor
	BSTree(BSTree& other);
	//Destructor
	~BSTree();
	//Insert Method
	bool insertNode(int data);
	//Delete Method
	void deleteNode(const int data);
	//Search Method
	bool searchNode(const int data);
	//Traverse Method
	void traverseTree(ostream& out);
	//Print Method
	void printTree(ostream& out);
	//Assignment Operator Overload
	const BSTree& operator=(BSTree& other);

private:
	Node* root;
	Node* copyHelper(Node* othTree);                    // Recurseve method that deep copies BST 
	bool searchHelper(int data,  Node* subTree) const;  // Recursive Method to Search Nodes
	void inorder(ostream& out,  Node* subTree) const;   // outputs list in order LVR
	void preorder(ostream& out,  Node* subTree) const;  // outputs list preorder VLR
	void postorder(ostream& out,  Node* subTree) const; // outputs list post order LRV
};
#endif 

