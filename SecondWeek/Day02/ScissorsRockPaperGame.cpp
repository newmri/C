// 1 ~ 3 사이 난수 준비 (컴퓨터가 낸 가위바위보)	
// 메뉴 구성
// 1.가위 2.바위 3.보 4.게임종료
// 총 3라운드 실시. 매 라운드 마다 난수를 새로 준비
// 게임이 끝나면 x승 x무 x패 출력 후 종료

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int num{}, sel{}, win{}, lose{}, draw{};
	for (int i = 0; i < 3; ++i) {
		cout << "1.가위 2.바위 3.보 4.게임종료" << endl;
		cout << "입력: ";
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
			cout << win << "승" << " " << draw << "무 " << lose << "패" << endl;
			return 0;
		}
	}

	cout << win << "승" << " " << draw << "무" << lose << "패" << endl;
	return 0;
}

