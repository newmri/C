#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str{ "Hello " };
	string str2{ "World" };

	cout << str + str2 << endl;
	cout << str.length() << endl;
	cout << sizeof(string) << endl;

	//char input[16]{};
	//cin.getline(input, 16); // Input with blank
	getline(cin, str); // Input with blank
	cout << str << endl;

	const char* name {"Hiya"};
	string st{ "Hiya" };

	system("pause");
}