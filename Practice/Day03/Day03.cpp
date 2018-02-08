#include <iostream>

using namespace std;

int main()
{
	// ##1. Variable Naming Rule.
	// 1. Name is composed of alphabet and number, However number can't be in front.
	// int 1a; fault!
	// int a1; ok!

	// 2. can't use special character. but, _ is allowed.
	// int a%; fault!
	// int __a; ok!

	// 3. Can't use empty
	// int player hp; fault!
	// int player_hp; ok!

	// 4. Vary capital and small letter.
	// int a = 100;
	// int A = 200;

	// 5. Name with use
	// int iAttack = 1;

	// 6. Can't use the same name in the same local area.
	// int a;
	// int a; error!

	// ##2. Default Operator
	// Operator: Return result of operation.
	// Operand: Target of Operation

	// unary Operator: 1 Operand
	// Transposition Operator: 2 Operand
	// Triple Operator: 3 Operand

	// ##3. Arthmetic Operation
	// Double Operator
	// + - * / %
	cout << 5 / 2 << endl; // Return quotient.
	cout << 5 % 2 << endl; // Return remain.

	// Can use priority order with ().
	cout << (1 + 1) + 2 * 2 + (1 + 1) << endl;

	// ##4. sizeof Operator
	// Return memory size by bytes.
	// Unary Operator

	bool bTrue = true;
	char ch = 'A';
	short nA = 10;
	int iA = 50;
	float fA = 3.14f;
	double dA = 3.1415;

	cout << "Size of bool" << sizeof(bool) << endl;
	cout << "Size of bTrue" << sizeof(bTrue) << endl;

	// Read rvalue and store to lvalue.
	// ##5. Substitution Operator
	// =
	// Transposition Operator

	// 1. Two variables must be same data type.
	// 2. Operation order operates from right to left.
	int a = 1, b = 2, c = 3;
	cout << (a = b = c) << endl; // Print out a's value

	// ##6. Relational Operator
	// <> <= >= == !=
	// Transposition Operator
	// Return true or false.
	{
		int a = 1, b = 2, c = 3;
		cout << (a < b) << endl;
		cout << (a > b) << endl;
	}

	// ##7. Logical Operator
	// &&(and) ||(or) -> Transposition Operator
	// !(not) -> Single Operator

	// &&(and) Operator
	// If two condition is true, return true.

	// ||(or)
	// If at least one condition is true, return true.

	cout << (true && false) << endl;
	cout << (true && true) << endl;

	// Don't operates after &&
	cout << (false && true) << endl;
	cout << (false && false) << endl;

	int k = 10;
	false && (k = 20);
	cout << k << endl;

	{
		int k = 10;
		// Don't operates before ||
		true || (k = 20);
		cout << k << endl;
	}

	// ##8. Bit Operator
	// Operand must be Integer.

	// 1. Bit Logic Operator
	// &(and), |(or), ~(not), ^(xor)

	// &(and)
	// Check bit column.
	// Compare with bit
	{
		short a = 10 & 8;
		short o = 10 | 8;
		// if two bits is true return 0, or not, return true.
		short x = 10 ^ 8;
		short n = 1;
		// 0000 0000 0000 1010
		// 0000 0000 0000 1000
		// 0000 0000 0000 1000
		cout << a << endl;

		// 0000 0000 0000 1010
		// 0000 0000 0000 1000
		// 0000 0000 0000 1010
		cout << o << endl;

		// 0000 0000 0000 1010
		// 0000 0000 0000 1000
		// 0000 0000 0000 0010
		cout << x << endl;

		// 0000 0000 0000 0001
		// 1111 1111 1111 1110
		//
		cout << ~n + 1 << endl;

		// 2. Bit Shift Operator
		// << >>
		
		short ls = 4 << 2;
		// 0000 0000 0000 0100
		// 0000 0000 0001 0000
		// x << n == x * 2^n
		cout << ls << endl;

		short rs = 4 >> 2;
		// 0000 0000 0000 0100
		// 0000 0000 0000 0001
		// x >> n == x / 2^n
		cout << rs << endl;
		cout << -rs << endl;

	}

	// ##9. Increment and Decrement Operator -> Unary Operator
	// ++ --
	{
		int a = 1;
		cout << a++ << endl;
		cout << ++a << endl;
	}

	// ##10. Abbreviation Operator
	// +=, -=, *=, /=, %=, &=, ^=, <<=, >>= ...
	{
		int a = 1;
		cout << (a += 9) << endl;
	}

	// ##11. Type Casting
	// Implication Casting
	// int a = 3.14f;
	// Explicit Casting
	cout << (char)65 << endl;
	{
		int a = 3;
		float b = 3.14f;
		// Integer vs Real Number -> Type Casting to Real Number
		cout << a + b << endl; // Implication Casting
		cout << a + (int)b << endl; // Explicit Casting

		int aa = 3;
		short bb = 1;
		// Same two types -> Type Casting to larger memory size
		cout << sizeof(aa + bb) << endl;

		char ch1 = 'a', ch2 = 'b';
		// Current Operation Result will be stored into temporary memory.
		cout << sizeof(ch1 + ch2) << endl;
	}

	// ##12. Get value from the keyboard.
	// cin: Object to get value from the keyboard.
	// >>: Insert Operator
	{
		int a = 0;
		cout << "Input Number: ";
		cin >> a;
		cout << "Result: " << a << endl;
	}


}