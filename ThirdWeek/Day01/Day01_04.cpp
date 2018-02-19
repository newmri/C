#include <iostream>

using namespace std;

// ##1. Array
// Set of Data

int main()
{
	int arr[5]{};
	int arr2[]{ 1,2,3 };
	cout << arr2[0] << endl;
	cout << arr2[1] << endl;
	cout << arr2[2] << endl;

	for (int i = 0; i < 3; ++i) cout << arr2[i] << endl;

	int arr3[2][3]
	{
		{1,2,3},
		{4,5,6}
	}; // [column][row], [y][x]
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) cout << arr3[i][j] << '\t'; // escape string recognizes as character
		cout << endl;
	}
	system("pause");
}