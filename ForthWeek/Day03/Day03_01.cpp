#include <iostream>

using namespace std;

// ##1. Dynamic Allocation
// Allocate and Deallocate memory when want

// ##2. Point to be needed using dynamic allocation
char* InputString()
{
	char* input = (char*)calloc(16, sizeof(char));
	cout << "Input: ";
	cin >> input;
	return input; // Dangling pointer
	
}

int main()
{
	char* str{ InputString() };
	cout << "Result: " << str << endl;
	free(str);
	str = nullptr;

	// ##3. Dynamic Allocation on C
	// 1.malloc
	// as much as size, allocate memory in heap memory and return address
	// void* malloc(size_t size)

	// Allocate memory
	int* p = (int*)malloc(sizeof(int));
	*p = 10;
	cout << *p << endl;
	// Deallocate memory
	free(p);
	p = nullptr; // to avoid dangling pointer

	// 2.calloc
	// as much as count, allocate memory in heap memory
	// Automatically initialize as 0
	int* ptr = (int*)calloc(5, sizeof(int));
	for (int i = 0; i < 5; ++i) cout << ptr[i] << endl;
	free(ptr);
	ptr = nullptr;

	// ##4. Static Array and Dynamic Array
	// 1. Static Array
	// Size will be determined when compile time
	// Unmodifiable
	// int arr[5]{};

	// 2. Dynamic Array
	// Modifiable
	//int size{ 5 };
	//{
	//	int* ptr = (int*)calloc(size, sizeof(int));
	//	for (int i = 0; i < size; ++i) cout << ptr[i] << endl;
	//	free(ptr);
	//	ptr = nullptr;
	//}
	//
	//{
	//	int** ptr = (int**)calloc(size, sizeof(int*));
	//	for (int i = 0; i < size; ++i) ptr[i] = (int*)calloc(size, sizeof(int));
	//	for (int i = 0; i < size; ++i) free(ptr[i]);
	//	free(ptr);
	//}

	//{
	//	int(*ptr)[5] = (int(*)[5])calloc(5, sizeof(int) * 5);
	//}

	system("pause");
}