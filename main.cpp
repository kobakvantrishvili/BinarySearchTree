#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int main() {

	int num, z;
	char c;
	BSTree something;

	// INSERT
	cout << "how many numbers do you want to insert into  a BST?" << endl;
	while (1) 
	{
		cin >> num;
		if (cin.fail() || num <= 0) 
		{
			cin.clear(); //Clears Error flags so user can enter new input 
			cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
			cout << "Please insert a valid number" << endl;
		}
		else 
		{
			break;
		}
	}

	cout << "please insert the numbers you want to be added to BST" << endl;
	for (int i = 0; i < num; i++) 
	{
		while (1)
		{
			cin >> z; 
			if (cin.fail()) 
			{
				cin.clear(); //Clears Error flags so user can enter new input 
				cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
				cout << "Please insert a valid number" << endl;
			}
			else 
			{
				if (!something.insertNode(z))
					num++;
				break;
			}
		}
	}
	//TRAVERSE
	something.traverseTree(cout);
	
	cout << "________________________________________________\n" << endl;

	//SEARCH
	do
	{
		cout << "what number do you want to search in BST?" << endl;
		cin >> num;
		if (cin.fail()) 
		{
			cin.clear(); //Clears Error flags so user can enter new input 
			cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
			cout << "Please insert a valid number" << endl;
		}
		else 
		{
			something.searchNode(num);
		}

		cout << "Do you want to  search more[Y/N]? ";
		while (1) {
			cin >> c;
			if (c == 'y' || c == 'Y' || c == 'n' || c == 'N') 
			{
				break;
			}
			else 
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please insert a valid answer[Y/N]? ";
			}
		}

	} while (c != 'N' && c != 'n');

	cout << "________________________________________________\n" << endl;

	do 
	{
		cout << "what number do you want to delete in BST?" << endl;
		cin >> num;
		if (cin.fail()) 
		{
			cin.clear(); //Clears Error flags so user can enter new input 
			cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
			cout << "Please insert a valid number" << endl;
		}
		else 
		{
			something.deleteNode(num);
		}

		cout << "\nDo you want to  delete more[Y/N]? ";
		while (1) {
			cin >> c;
			if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please insert a valid answer[Y/N]? ";
			}
		}

	} while (c != 'n' && c != 'N');

	something.traverseTree(cout);

	cout << "________________________________________________\n" << endl;

	//PRINT
	cout << "Output of printTree Method:";
	something.printTree(cout);

	cout << "________________________________________________\n" << endl;

	//COPY CONSTRUCTOR
	cout << "Output of Copyconstructed BST's Traverse Method:";
	BSTree Test1(something);
	Test1.traverseTree(cout);

	cout << "________________________________________________\n" << endl;

	//ASSIGNMENT OPERATOR
	BSTree Test2;
	Test2.insertNode(6);
	Test2.insertNode(9);
	Test2.insertNode(4);
	Test2.insertNode(5);
	Test2.insertNode(2);
	Test2.insertNode(3);
	Test2.insertNode(1);
	Test2.insertNode(8);
	cout << "Initial Value of Test 2 BST:" << endl;
	Test2.printTree(cout);
	cout << "After Assigning Test 1 to Test 2:";
	Test2 = Test1;
	Test2.printTree(cout);

	cout << "________________________________________________\n" << endl;

	//DESTRUCTOR
	cout << "\nOutput of Destructor :" << endl;
	cout << endl;

}