#include <iostream>

using namespace std;

int main()
{
	// ##1. do ~ while
	/*do {
		1. Execute this line.
		3. When condition is true, repeat do.
	} while (condition); 2. Check condition.*/

	//int i{};

	//do {
	//	cout << "Hello World" << endl;
	//} while (--i);

	//{
	//	// �Է��� ���� ������� ���� -1�� �Է��ϸ� ���� ����, ��� ���, if�� �̿� ���� ����
	//	int input{}, ret{};
	//	do {
	//		ret += input;
	//		cout << "�Է�: "; cin >> input;
	//	} while (input != -1);
	//	cout << "�������: " << ret << endl;
	//}

	// ##2. for
	// while: When need infinitive repeat.
	// for: Repeat with specific times.
	//for (1.Init; 2.Condition; 4.InDecrement) {
	//	3.Repeat when condition is true.
	//}
	//for (int i = 0; i < 3; ++i) cout << "Hello World" << endl;
	//int i{};
	//for (; i < 3;) { cout << "Hello World with omit" << endl; ++i; }

	//for(int i = 1; i <= 9; ++i) cout << "2 * " << i << " = " << 2 * i << endl;

	// ##3. Double For

	for (int i = 2; i < 10; ++i) for (int j = 1; j < 10; ++j) cout << i << " * " << j << " = " << i * j << endl;
	

}