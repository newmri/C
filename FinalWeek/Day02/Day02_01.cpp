#include <iostream>

using namespace std;

// ##1. Reference
// Direct reference

void Swap(int& a, int& b)
{
	int temp{ b };
	b = a;
	a = temp;
}

int main()
{
	// ##2. Reference Declare
	int n{};

	int& r = n; // can call n by calling r
	r = 1;
	cout << n << endl;
	cout << "n: " << &n << endl;
	cout << "r: " << &r << endl;

	// ##3. Difference between pointer and reference
	int* ptr = nullptr; // ok
	//int& r = 0; // fail

	// ##4. Swap by reference
	int a{1}, b{2};
	Swap(a, b);
	cout << a << " " << b << endl;

	// ##5. reference and const
	const int k = 1;
	const int& j = k;
	const int& l = 100; // Create l variable

	system("pause");
}