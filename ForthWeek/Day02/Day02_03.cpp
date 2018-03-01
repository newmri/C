#include <iostream>

using namespace std;

// ##1. union
// Set of relative data

union uniBox
{
	short	a;
	int		b;
};

struct tagBox
{
	short	a;
	int		b;
};

typedef union uniMatrix
{
	struct  
	{
		float _11, _12, _13;
		float _21, _22, _23;
		float _31, _32, _33;
	};
	float m[3][3];
}MAT;

int main()
{
	// ##2. structure vs union
	cout << sizeof(uniBox) << endl;
	cout << sizeof(tagBox) << endl;
	
	uniBox uBox;
	tagBox tBox;

	// Union shares all memory
	cout << &(uBox.a) << endl;
	cout << &(uBox.b) << endl;

	MAT mat;
	mat._22 = 10.0f;
	cout << mat.m[1][1] << endl;

	system("pause");


}