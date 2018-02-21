#include <iostream>

using namespace std;

void Func(int ptr[], int size)
{
	for (int i = 0; i < size ; ++i) cout << ptr[i] << endl;
}

int main()
{
	// ##1. Pointer and const
	int a{}, b{};
	// const int* ptr = &a;
	// *ptr = 1; // error

	int* const ptr = &a;
	//ptr = &b; // error constant pointer

	// ##2. Data type of array
	int arr[5]{ 1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Func(arr, size);

	// ##3. 2 dimension pointer type of array
	{
		int arr[2][3]{ 1,2,3,4,5,6 };
		cout << arr << endl;
		cout << "-------------------------" << endl;
		cout << sizeof(arr) << endl; // total size
		cout << sizeof(arr[0]) << endl; // 0 column size
		cout << "-------------------------" << endl;
		cout << arr << endl;
		cout << arr + 1 << endl; // move to next column

		// 2 dimension pointer type of array: type(*pointer)[size of row]
		int(*ptr)[3]{ arr };
		cout << ptr[1][1] << endl;
		cout << *(ptr[1] + 1)<< endl;
		cout << (*(ptr+ 1))[1] << endl;
		cout << *(*ptr + 4) << endl;

		cout << ptr << endl; // starting address of 2 dimension
		cout << *ptr << endl; // starting address of 1 dimension
		cout << **ptr << endl; // This is not double pointer
	}

	system("pause");
}	