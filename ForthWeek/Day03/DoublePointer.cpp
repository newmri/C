#include <iostream>

using namespace std;

void func(int* p)
{
	cout << "func(int*): " << &p << endl;
}

void func(int** p)
{
	cout << "func(int**): " << &(*p) << endl;
}

int main()
{
	int* p = nullptr;
	cout << "main() p: " << &p << endl;
	func(p);
	func(&p);

	system("pause");
}