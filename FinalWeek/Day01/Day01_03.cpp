#include <iostream>

using namespace std;

int main()
{
	{
		// ##1. Binary Mode Output

		int arr[5]{ 1,2,3,4,5 };

		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, "../Data/binary.txt", "wb");
		if (0 == err) {
			// fwrite: binary output function
			//fwrite(arr, sizeof(int), sizeof(arr) / sizeof(int), fp);
			fwrite(arr, sizeof(arr), 1, fp);
			fclose(fp);
		}
		else cout << "File Open Fail" << endl;
	}

	{
		// ##2. Binary Mode Input

		int arr[5]{};

		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, "../Data/binary.txt", "rb");
		if (0 == err) {
			// fread: binary input function
			// if there is no data to read more, return less value than count argument
			fread(arr, sizeof(arr), 1, fp);
			fclose(fp);
		}
		else cout << "File Open Fail" << endl;

		for (int i = 0; i < 5; ++i) cout << arr[i] << endl;
	}

	// Advantage of using binary mode
	// Serial data can be input output at one's
	// faster than text mode

	system("pause");
}