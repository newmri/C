// Comment: Exclude this line from compile.

// #: Preprocess Indicator
// #include<>: Include <> file before compile. 
// <iostream>: C++ Standard Input Output Header File
// <stdio.h>: C Standard Input Output Header File
#include <iostream>

// using: Indicator
// namespace: Space to avoid collision of same name from c++.
using namespace std;

//using std::cout;
//using std::endl;

namespace A
{
	void Draw()
	{
		cout << "Called A Draw() Function" << endl;
	}
}

namespace B
{
	void Draw()
	{
		cout << "Called B Draw() Function" << endl;
	}
}

// Main Function: Entry Point
// One main function is to be included in one program.
int main()
{
	// cout(console out): Object on c++ to print something.
	// <<: Extract Operator
	// endl(end line): Object on c++ to end current line.
	// "Hello world": Characters
	// ; End of Line
	cout << "Hello World on C++" << endl;

	// 'A': Single Character
	cout << 'a' << endl;

	// Function of C
	// \n: Line Switch Character
	printf("Hello World on C \n");

	// Comment: Control + k + c
	// Uncomment: Control + k + u

	// ::(Scope Operator, namespace Operator)
	A::Draw(); // Call A::Draw() function.
	B::Draw(); // Call B::Draw() function.
}