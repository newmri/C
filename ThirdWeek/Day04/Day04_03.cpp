#include <iostream>

using namespace std;

// Function Pointer usually utilized in order to give algorithm condition
bool Greater(int a, int b) // Descendant
{
	return a < b;
}

bool Less(int a, int b) // Ascendant
{
	return a > b;
}

void Sort(int arr[], int cnt, bool(*ptr)(int,int))
{
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; j < cnt - 1; ++j) {
			if (ptr(arr[j], arr[j + 1])) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[5]{ 5,1,3,4,2 };
	Sort(arr, 5, Greater);
	
	for (int i = 0; i < 5; ++i) cout << arr[i] << endl;

	system("pause");
//}