#include <iostream>

using namespace std;

int Add(int a, int b) { return a + b; }
int Min(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

int main()
{

	// Can simplify using Function Pointer

	{
		int op1{}, op2{}, sel{};
		int(*ptr)(int, int) = nullptr;

		cout << "Input operand 1:";
		cin >> op1;
		cout << "Input operand 2:";
		cin >> op2;

		cout << "1.Add 2. Subtract 3. Multiply 4. Divide: ";
		cin >> sel;
		switch (sel) {
		case 1: ptr = Add; break;
		case 2: ptr = Min; break;
		case 3: ptr = Mul; break;
		case 4: ptr = Div; break;
		}

		cout << ptr(op1, op2) << endl;
	}

	{
		int op1{}, op2{}, sel{};
		int(*ptr[4])(int, int){ Add, Min, Mul, Div };

		cout << "Input operand 1:";
		cin >> op1;
		cout << "Input operand 2:";
		cin >> op2;

		cout << "1.Add 2. Subtract 3. Multiply 4. Divide: ";
		cin >> sel;

		cout << ptr[sel - 1](op1, op2) << endl;
	}
	system("pause");
}