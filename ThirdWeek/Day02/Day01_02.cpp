#include <iostream>

using namespace std;

// ##1. Array and Pointer
int main()
{
	// ##2. Array has sequential spot
	int arr[5]{};
	for (int i = 0; i < 5; ++i) {
		cout << i << ": ";
		cout << &(arr[i]) << endl;
	}

	// ##3. Meaning of array name: Know address of starting point (array)
	cout << "arr: " << arr << endl; // Name of array has first address

	// ##4. Pointer Operationnewegg
	// Can do +, - Operation
	// Have to be sequential spot
	cout << arr + 1 << endl;

	// ##5. Name of array is constant pointer
	int a{ 10 };
	//arr = &a;
	system("pause");

}