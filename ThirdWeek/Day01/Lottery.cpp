// ����3.
// �ζ� ����
// 1 ~ 45 ������ ���� �ߺ����� �����ϰ� 6�� ����
// �� 6ȸ�� �� ȸ�������� �ߺ��� ���� ����� ��
// �� ȸ������ �������� ����
// 1ȸ��
// 5 1 4 3 45 21 - > 1 3 4 5 21 45

#include <iostream>
#include <ctime>

using namespace std;

void Update();
void SetLotteryNum(int lottery[], int& newNum);
void Sort(int lottery[]);

const unsigned int NUM = 6;
int main()
{
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < NUM; ++i) {
		cout << i + 1 << "ȸ�� ��ȣ: ";
		Update();
	}

	system("pause");
}

void SetLotteryNum(int lottery[], int& newNum)
{
	bool chk{ false };
	for (int i = 0; i < NUM; ++i) if (lottery[i] == newNum) chk = true;
	if (!chk) {
		for (int i = 0; i < NUM; ++i) {
			if (lottery[i] == 0) {
				lottery[i] = newNum;
				break;
			}

		}
	}
}

void Sort(int lottery[])
{
	int tmp{};

	for (int i = 0; i < NUM - 1; ++i) {
		for (int j = 0; j < NUM - 1 - i; ++j) {
			if (lottery[j] > lottery[j + 1]) {
				tmp = lottery[j];
				lottery[j] = lottery[j + 1];
				lottery[j + 1] = tmp;
			}
		}
	}
}

void Update()
{
	int lottery[NUM]{}, num{};
	while (true) {
		if (lottery[NUM - 1] == 0) {
			num = rand() % 45 + 1;
			SetLotteryNum(lottery, num);
		}

		else break;
	}

	Sort(lottery);
	for (int i = 0; i < NUM; ++i) cout << lottery[i] << "\t";
	cout << endl;
}