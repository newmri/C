#include <iostream>

using namespace std;

int main()
{
	// ##1. Branch
	// Seperate flow of code by condition.
	// if, switch, goto

	// ##2. if
	/*if (condition)
	{
		Process this line when condision is true
	}*/

	int select = 0;
	cout << "Select: ";
	cin >> select;
	if (1 == select) cout << "Cola" << endl;
	else if (2 == select) cout << "Milk" << endl;
	else cout << "Sprite" << endl; // Pair with if

	// ##3.
	// (operand1) ? (operand2) : (operand3)
	// (condition) ? (return when true) : (return when false)
	// Simple
	(5 == 5) ? (cout << "true" << endl) : (cout << "false" << endl);

}