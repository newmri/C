// 과제3.
// 로또 구현
// 1 ~ 45 사이의 수를 중복없이 랜덤하게 6개 추출
// 총 6회차 한 회차에서는 중복된 수가 없어야 함
// 각 회차별로 오름차순 정렬
// 1회차
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
		cout << i + 1 << "회차 번호: ";
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