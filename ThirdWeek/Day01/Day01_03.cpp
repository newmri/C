#include <iostream>

using namespace std;

// ##1. Recursive Function
// Call same function.
// Break is vital.
// When do not be aware of how many times have to be called function, this is useful.

// factorial
// 3! = 3 * 2 * 1
// 5! = 5 * 4 * 3 * 2 * 1
// n! = n * n - 1 * n - 2 * 1
// Break Condition: n - x == 1
// Stack Overflow!
//void Recursive(){ Recursive(); }

int Factorial(int n);

int main()
{
	cout << Factorial(3) << endl;

	system("pause");
}

int Factorial(int n)
{
	if (n == 1) return 1;
	else return Factorial(n - 1) * n;
}