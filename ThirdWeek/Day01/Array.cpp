// 과제1.
// 1차원 배열과 2중 for문 이용 출력, 분기문 사용 x
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25

#include <iostream>

using namespace std;

int main()
{
	int arr[25]{}, num{};
	for (int i = 0; i < 25; ++i) arr[i] = i + 1;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) cout << arr[j + i * 5] << " ";
		for (int k = 0; k == 0; ++k) cout << endl;
	}

	system("pause");
}