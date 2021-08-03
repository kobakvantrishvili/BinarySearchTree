#include "BST.h"
#include "TreeNode.h"

BSTree::BSTree()
{
	root = NULL;
}

BSTree::BSTree(BSTree& other)
{
	root = copyHelper(other.root);
	cout << "\nSuccesfully Copied!" << endl;
}


BSTree::~BSTree()
{
	Node* curr = root;
	Node* parr = NULL;
	bool isleft = false;
	while (curr != NULL) {
		curr = root;
		parr = NULL;

		while (1) 
		{
			if (curr->left != NULL)
			{
				parr = curr;
				curr = curr->left;
				isleft = true;
			}
			else if (curr->right != NULL)
			{
				parr = curr;
				curr = curr->right;
				isleft = false;
			}
			else
			{
				break;
			}
		}
		
		if (isleft == true)
		{
			if(parr != NULL)
			{
				parr->left = NULL;
			}
			
		}
		else
		{
			if (parr != NULL)
			{
				parr->right = NULL;
			}
			
		}
		cout << "Number " << curr->getValue() << " deleted" << endl;
		delete curr;
		curr = parr;
	}
	cout << endl;
}

bool BSTree::insertNode(const int data)
{
	Node* local  = root,
		* parent = NULL;
	bool found = false;

	while (local != NULL && found == false) {
		if (data < local->getValue())
		{
			parent = local;
			local = local->left;
		}
		else if (data > local->getValue())
		{
			parent = local;
			local = local->right;
		}
		else
			found = true;
	}
	
	if (!found) 
	{
		Node* newNode = new Node(data);
		if (parent == NULL)
			root = newNode;
		else if (data < parent->getValue())
			parent->left = newNode;
		else
			parent->right = newNode;

		return true;
	}
	else
	{
		cout << "value " << data << " already exists in the Binary Tree" << endl;
		return false;
	}
}

void BSTree::deleteNode(const int data)
{
	Node* target = root,
		* parent = NULL;
	bool found = false;
	bool isleft;
	while (target != NULL && found == false) {
		if (data < target->getValue())
		{
			parent = target;
			target = target->left;
			isleft = true;
		}
		else if (data > target->getValue())
		{
			parent = target;
			target = target->right;
			isleft = false;
		}
		else
			found = true;
	}
	if (found && parent != NULL)
	{
		if (target->left != NULL && target->right != NULL)
		{
			Node* inSuccessor = target->right;
			while (inSuccessor->left != NULL)
				inSuccessor = inSuccessor->left;

			target->setValue(inSuccessor->getValue());

			parent = target;
			target = target->right;
			isleft = false;
			while (target != inSuccessor)
			{
				parent = target;
				target = target->left;
				isleft = true;
			}
		}


		if (isleft)
		{
			if (target->right == NULL)
				parent->left = target->left;
			else if (target->left == NULL)
				parent->left = target->right;
		}
		else if (!isleft)
		{
			if (target->right == NULL)
				parent->right = target->left;
			else if (target->left == NULL)
				parent->right = target->right;
		}

		delete target;
	}
	else
		if (!found)
			cout << "value " << data << " doesn't exist in Binary Tree" << endl;
		else
			cout << "You can't delete the Root" << endl;
}

bool BSTree::searchNode(const int data)
{
	if (searchHelper(data, root))
	{
		cout << "number " << data << " is in the BST\n" << endl;
		return true;
	}
	else
	{
		cout << "number " << data << " is not the part of BST\n" << endl;
		return false;
	}
}

void BSTree::traverseTree(ostream& out)
{
	out << "\nTraversing Binary Tree in 3 types of orders" << endl;
	out << "inorder: ";
	inorder(out, root);
	out << "\nPreorder: ";
	preorder(out, root);
	out << "\nPostorder: ";
	postorder(out, root);
	cout << endl;
}

void BSTree::printTree(ostream & out)
{
	out << "\nBinary Search Tree preorder: " << endl;
	preorder(out, root);
	cout<<"\n"<< endl;
}

const BSTree& BSTree::operator=(BSTree& other)
{
	if (&other != this)
	{
		BSTree temp(other);
		cout << "deleting the old values of BST:" << endl;
		swap(temp.root, root); //  This function swaps the addresses to which pointers are pointing to
	}
	cout << "Succesfully Assigned!" << endl;

	return *this;
}

bool BSTree::searchHelper(int data,  Node* subTree) const
{
	if (subTree == NULL)
		return false;
	else if (data < subTree->getValue())
		return searchHelper(data, subTree->left);
	else if (data > subTree->getValue())
		return searchHelper(data, subTree->right);
	else
		return true;
}

Node* BSTree::copyHelper(Node* othTree)
{
	if (othTree == NULL)
	{
		return NULL;
	}
	else
	{
		Node* newNode = new Node(othTree->getValue());

		newNode->left = copyHelper(othTree->left);
		newNode->right = copyHelper(othTree->right);

		return newNode;
	}
}

void BSTree::inorder(ostream& out,  Node* subTree) const
{
	if (subTree != NULL) {
		inorder(out, subTree->left);        //L
		out << subTree->getValue() << " ";  //V
		inorder(out, subTree->right);       //R
	}
	
}

void BSTree::preorder(ostream& out,  Node* subTree) const
{
	if (subTree != NULL) {
		out << subTree->getValue() << " ";  //V
		preorder(out, subTree->left);       //L
		preorder(out, subTree->right);      //R
	}
}

void BSTree::postorder(ostream& out,  Node* subTree) const
{
	if (subTree != NULL) {
		postorder(out, subTree->left);      //L
		postorder(out, subTree->right);     //R
		out << subTree->getValue() << " ";  //V
	}
}
