#include <iostream>

using namespace std;

char* InputString()
{
	char* input = new char[16];
	cout << "Input: ";
	cin >> input;
	return input; // Dangling pointer

}

int main()
{
	// ##1. Dynamic Allocation on C++
	// new: Allocation
	// delete: DeAllocation
	{
		int* p = new int[2]{ 100, 100 };
		delete[] p;
		p = nullptr;
	}

	{
		char* str{ InputString() };
		cout << "Result: " << str << endl;
		delete[] str;
		str = nullptr;
	}

	system("pause");
}