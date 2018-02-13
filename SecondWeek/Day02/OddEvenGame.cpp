
// 1 ~ 10 사이의 난수 준비
// 메뉴를 구성
// 1.홀 2. 짝 3.게임종료
// 사용자가 홀 또는 짝을 선택하여 준비한 난수가 짝인지 홀인지 맞춤
// 총 3라운드 실시, 매 라운드 마다 난수를 새로 준비
// 게임이 끝나면 x승 x패 출력후 종료

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int num{}, sel{}, win{}, lose{};
	for (int i = 0; i < 3; ++i) {
		cout << "1.홀 2.짝 3.게임종료" << endl;
		cout << "입력: ";
		cin >> sel;
		srand(unsigned int(time(nullptr)));
		num = rand() % 10 + 1;
		if (sel == 1) {
			if (num % 2 != 0) {
				++win;
				cout << "당신의 승리!" << endl;
			}
			else {
				++lose;
				cout << "당신의 패배!" << endl;
			}
		}
		else if (sel == 2) {
			if (num % 2 == 0) {
				++win;
				cout << "당신의 승리!" << endl;
			}
			else {
				++lose;
				cout << "당신의 패배!" << endl;
			}
		}
		else {
			cout << win << "승" << " " << lose << "패" << endl;
			return 0;
		}
	}

	cout << win << "승" << " " << lose << "패" << endl;
	return 0;
}

