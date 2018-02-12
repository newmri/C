#include <iostream>

using namespace std;

int main()
{
	// ##1. Loop
	// while, do while, for
	
	// ##2. while
	// during condition is true.
	//while (condition) {
	//	// code
	//}

	int n{};
	while (n++ < 3) cout << "Hello World" << endl;
	
	// 연습 문제
	// 구구단 2단 출력
	int cnt{};
	while (++cnt <= 9) cout << "2 * " << cnt << " = " << 2 * cnt << endl;

	// ##3. break
	int num{};
	while (true) {
		if (num > 2) break;

		cout << "Hello World With break" << endl;
		num++;
	}

	// ##4. continue
	// Skip and Repeate
	{
		int cnt{};
		while (cnt++ < 5) {
			cout << "Hello" << endl;
			continue;
			cout << "World" << endl;
		}
	}

	// ##5. System Function
	cout << "Hello With pause" << endl;
	system("pause");
	system("cls"); // Clear screen.
	cout << "World" << endl;
}