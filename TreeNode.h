#pragma once
#ifndef TREENODE
#define TREENODE
#include <iostream>

using namespace std;

class Node {

	friend class BSTree;

private:
	Node* left;
	Node* right;
	int value;
	

public:
	//Constructor
	Node()
	:value(0), left(0), right(0)
	{}
	//Excplicit Value Constructor
	Node(int inValue, Node* inLeft = NULL, Node* inRight = NULL)
	:value(inValue), left(inLeft), right(inRight)
	{}
	//Getter Function
	inline int getValue() const
	{
		return value;
	}
	//Setter Function
	inline void setValue(int newVal)
	{
		value = newVal;
	}
};


#endif 
