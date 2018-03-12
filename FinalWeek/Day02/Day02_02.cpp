#include <iostream>

using namespace std;

// ##1. Macro
#define PI 3.141592f

// ##2. Macro Function
#define SQUARE(X) X * X

#define SAFE_DELETE(P) if(P != nullptr) { delete P; P = nullptr }
#define SAFE_DELETE2(P) \
if(P != nullptr) { delete P; P = nullptr }


int main()
{
	cout << PI << endl;
	cout << SQUARE(9) << endl;

	int* ptr = nullptr;

	system("pause");
}
