#include <iostream>

using namespace std;

// ##1. string functions
// strlen
// strcpy_s
// stcat_s
// strcmp


int main()
{
	{
		// ##2. strlen
		char name[16]{ "Hello" };
		cout << strlen(name) << endl;
	}

	{
		// ##3. strcpy_s
		char name1[16]{ "Hello" };
		char name2[16]{};
		// name of array is constant pointer
		//name2 = name1; // error
		strcpy_s(name2, sizeof(name1), name1);
		cout << name2 << endl;

	}

	{
		// ##4. strcat_s
		char name1[16]{"Hello" };
		char name2[16]{ " World" };
		strcat_s(name1, sizeof(name2), name2);
		cout << name1 << endl;
	}

	{
		// ##4. strcat_s
		char name1[16]{ "Hello" };
		char name2[16]{ " World" };
		if(strcmp(name1, name2) == 0) cout << "Same string" << endl;
		else cout << "Different string" << endl;
	}

	system("pause");
}