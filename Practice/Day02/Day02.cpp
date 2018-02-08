#include <iostream>

using namespace std;

int main()
{
	//##1. Data Type and Variables
	// Variable: Set memory spot and name it.
	// Whenever data in variable can be modified.

	//##2. Kind of Data Type
	// 1. Integer (short, int, long, long long)
	// 2. Real Number (float, double, long double)
	// 3. Character (char)
	// 4. Logic (From C++) (bool)

	//##3 Size of Data Type
	// 1byte (8bits) (char, bool)
	// 2bytes (16bits) (short)
	// 4bytes (32bits) (int, float, long)
	// 8bytes (64bits) (long, double, long double)
	// unsigned char 0 ~ 255
	// unsigned short 0 ~ 66535
	// unsigned int, long 0 ~ 4294967296 (42Bills)

	// signed MSB 0: positive(+) 1: negative(-)
	// Sign Reverse: Mark of 2
	
	//##4 Variable Definition and Initialization
	// Variable Definition: Set memory spot in order to store value.
	// int a; // Here is garbage value.
	// int a = 0; So, this is batter way
	
	// Variable Initialization: Set value into variable at first time.
	// a = 777;

	//##5. Constant (Can't be modified)
	// const int n = 0;
	// n = 999; // Can't do this!
	// Literal Constant: Fixed Number
	// When CPU calculate something, operand must be in memory.
	// Thus, literal constant and result of operation will be stored in temporary memory.
	// Default Data Type: integer

	//##6 Why append f keyword to float?
	// If not, default is double.
	// It will miss data.


	// cout << 10 + 20 << endl;

	// Data Type
	// 1. Determin what kind of data will store.
	// 2. Memory size is up to data type.

	int /*Data Type*/ a /*variable name*/ = 10; // Store data in a variable. -> Write
	float b = 10.0f;

	cout << a << endl; // Read data from a variable. -> Read
	a + a; // Read data from a variable and add. -> Read
	a = 999; // Write

	cout << a << endl;

}