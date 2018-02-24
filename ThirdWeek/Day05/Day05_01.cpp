#include <iostream>

using namespace std;

int main()
{
	// ##1. string
	char name[]{ 'h','e','l','l','o' };
	char name2[]{ 'h','e','l','l','o','\0' };
	char name3[]{ "hello" };
	// When faced cout and char* print out string stored
	// '\0' means end of string
	//cout << name << endl;
	cout << name2 << endl;

	// ##2. constant string
	// Stored on data spot
	cout << "hello world" << endl;
	const char* pName = "hello world";
	cout << pName << endl;
	cout << (int*)"hello world" << endl;
	cout << (int*)pName << endl;

	// ##3. Get string through cin
	// When faced cin and char* string will be stored on memory
	// Correct
	char input[16]{};
	cin >> input;

	// Wrong
	//char* input = nullptr;
	//cin >> input; // don't have reference
	system("pause");
}