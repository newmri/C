
// 1 ~ 10 ������ ���� �غ�
// �޴��� ����
// 1.Ȧ 2. ¦ 3.��������
// ����ڰ� Ȧ �Ǵ� ¦�� �����Ͽ� �غ��� ������ ¦���� Ȧ���� ����
// �� 3���� �ǽ�, �� ���� ���� ������ ���� �غ�
// ������ ������ x�� x�� ����� ����

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int num{}, sel{}, win{}, lose{};
	for (int i = 0; i < 3; ++i) {
		cout << "1.Ȧ 2.¦ 3.��������" << endl;
		cout << "�Է�: ";
		cin >> sel;
		srand(unsigned int(time(nullptr)));
		num = rand() % 10 + 1;
		if (sel == 1) {
			if (num % 2 != 0) {
				++win;
				cout << "����� �¸�!" << endl;
			}
			else {
				++lose;
				cout << "����� �й�!" << endl;
			}
		}
		else if (sel == 2) {
			if (num % 2 == 0) {
				++win;
				cout << "����� �¸�!" << endl;
			}
			else {
				++lose;
				cout << "����� �й�!" << endl;
			}
		}
		else {
			cout << win << "��" << " " << lose << "��" << endl;
			return 0;
		}
	}

	cout << win << "��" << " " << lose << "��" << endl;
	return 0;
}

