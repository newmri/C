#include <iostream>

using namespace std;

// ##1. memory functions
// memset: Init by byte unit
// memcpy: Copy directly without temp buffer
// memmove: Copy through temp buffer

int main()
{
	{
		// ##2. memset
		int dst;
		memset(&dst, 0, sizeof(dst));
		cout << dst << endl;
	}

	{
		// ##3. memcpy
		int src[3]{ 1,2,3 };
		int dst[3]{};
		memcpy(dst, src, sizeof(src));
		for (int i = 0; i < 3; ++i) cout << dst[i] << "\t";
		cout << endl;

	}

	{
		// ##3. memmove
		int src[3]{ 1,2,3 };
		int dst[3]{};
		memmove(dst, src, sizeof(src));
		for (int i = 0; i < 3; ++i) cout << dst[i] << "\t";
		cout << endl;

	}
	system("pause");
}