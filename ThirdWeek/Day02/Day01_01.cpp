#include <iostream>
using namespace std;

// Reference: Access to memory
// Direct Reference: Access memory by name of variable
// Indirect Reference: Pointer(Access memory by address

// ##1. Pointer
// Variable witch has address
// Pointer has address of memory

void DoSomething(int num){ ++num; }
void DoSomething(int* num) { ++(*num); }
void Swap(int& lv, int& rv)
{
	int tmp{ lv };
	lv = rv;
	rv = tmp;
}
int main()
{
	int num{};
	DoSomething(num); // Call by value
	cout << "Call by value: " << num << endl;

	// ##3. Address of memory
	// Allocated recognizable address every memory by OS
	// Set address as 1byte
	// &(Address Operator)
	// Return address of memory
	cout << "Address of num: " << &num << endl;

	// Declare pointer
	// Add *
	int* ptr{ &num };
	cout << "ptr: " << ptr << endl;
	// Indirect Reference
	*ptr = 1;
	cout << "After *ptr = 1: " << num << endl;

	DoSomething(&num); // Call by value
	cout << "Call by pointer: " << num << endl;

	int* p1{ nullptr }, *p2{ nullptr }, *p3{ nullptr };

	// ##6. Size of pointer
	// On 32 bits system, 4bytes
	// On 64 bits system, 8bytes
	cout << sizeof(char*) << endl;
	cout << sizeof(int*) << endl;

	int a{ 10 }, b{ 20 };
	Swap(a, b);
	cout << a << ", " << b << endl;

	// ##7. Double Pointer: Pointer variable stores another pointer
	{
		int a{ 10 };
		int* ptr{ &a }; // Single Pointer
		int** pptr{ &ptr }; // Double Pointer

		cout << "Address of ptr: " << &ptr << endl;
		cout << "Value of pptr: " << pptr << endl;
		cout << "-----------------------" << endl;
		cout << "Address of a: " << &a << endl;
		cout << "Value of ptr: " << ptr << endl;
		cout << "Indirect reference of pptr: " << *pptr << endl;
		cout << "-----------------------" << endl;
		cout << "Value of a: " << a << endl;
		cout << "Value of *ptr: " << *ptr << endl;
		cout << "Value of **ptr: " << **pptr << endl;

		cout << sizeof(int*) << endl;

	}
	system("pause");
}