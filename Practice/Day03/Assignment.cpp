#include <iostream>

using namespace std;

static const float MAX_SOCRE = 100.0f;
static const int NUM_OF_SUBJECT = 3;

int main()
{
	float korean{}, eng{}, math{};
	float result{};

	cout << " -- 국영수 입력 -- " << endl;
	do{
		cout << "국어점수 입력: ";
		cin >> korean;

		cout << "영어점수 입력: ";
		cin >> eng;

		cout << "수학점수 입력: ";
		cin >> math;

	} while (korean > MAX_SOCRE || eng > MAX_SOCRE || math > MAX_SOCRE);

	result = korean + eng + math;

	cout << " -- 출력 결과 -- " << endl;
	cout << "국어점수: " << korean << endl;
	cout << "영어점수: " << eng << endl;
	cout << "수학점수: " << math << endl;
	cout << "총점: " << result << endl;
	cout << "평균: " << (result / static_cast<float>(NUM_OF_SUBJECT)) << endl;
}