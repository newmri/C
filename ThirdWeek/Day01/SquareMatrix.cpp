// 과제2.
// 2차원 배열을 이용해서 n * n 형태의 정방행렬을 시계방향으로 90도 회전

// 1 2 3 -> 7 4 1 - > 9 8 7
// 4 5 6    8 5 2     6 5 4
// 7 8 9    9 6 3     3 2 1

#include <iostream>

using namespace std;

void Rotate(int arr[3][3]);
void ShowArray(int arr[3][3]);

int main()
{
	int arr[3][3]{}, num{}, sel{};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) arr[i][j] = ++num;
	}

	ShowArray(arr);

	while (true) {
		cout << "Input 1 to rotate number: ";
		cin >> sel;
		if (sel == 1) {
			Rotate(arr);
			ShowArray(arr);
		}

		else return 0;
	}


	system("pause");
}

void Rotate(int arr[3][3])
{
	int tmp[3][3]{};
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) tmp[i][j] = arr[i][j];

	//for (int i = 0, k = 2; i < 3; ++i, --k) {
	//	for (int j = 0; j < 3; ++j) arr[j][k] = tmp[i][j];
	//}
	// after column: row of before
	// after row: (size - 1) - before column
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) arr[j][(3-1)-i] = tmp[i][j];
	
}

void ShowArray(int arr[3][3])
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) cout << arr[i][j] << " ";
		cout << endl;
	}
}