// 1 ~ 3 ���� ���� �غ� (��ǻ�Ͱ� �� ����������)	
// �޴� ����
// 1.���� 2.���� 3.�� 4.��������
// �� 3���� �ǽ�. �� ���� ���� ������ ���� �غ�
// ������ ������ x�� x�� x�� ��� �� ����

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int num{}, sel{}, win{}, lose{}, draw{};
	for (int i = 0; i < 3; ++i) {
		cout << "1.���� 2.���� 3.�� 4.��������" << endl;
		cout << "�Է�: ";
		cin >> sel;
		srand(unsigned int(time(nullptr)));
		num = rand() % 3 + 1;
		switch (sel) {
		case 1:
			if (num == 1) ++draw;
			else if (num == 2) ++lose;
			else ++win;
			break;
		case 2:
			if (num == 2) ++draw;
			else if (num == 3) ++lose;
			else ++win;
			break;
		case 3:
			if (num == 3) ++draw;
			else if (num == 1) ++lose;
			else ++win;
			break;
		case 4:
			cout << win << "��" << " " << draw << "�� " << lose << "��" << endl;
			return 0;
		}
	}

	cout << win << "��" << " " << draw << "��" << lose << "��" << endl;
	return 0;
}

