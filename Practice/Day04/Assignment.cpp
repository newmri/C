#include <iostream>

using namespace std;

static const float MAX_SOCRE = 100.0f;
static const int NUM_OF_SUBJECT = 3;

int main()
{
	{
		// 과제1. 정수 하나를 입력받아서 음수인지 양수인지 판별, if문 이용, (0은 양수)
		cout << "과제1.정수 하나를 입력받아서 음수인지 양수인지 판별, if문 이용, (0은 양수)" << endl;
		int num{};
		cout << "정수 입력: ";
		cin >> num;
		if (num >= 0) cout << "양수입니다" << endl;
		else cout << "음수입니다" << endl;
	}
	{
		// 과제2. 두 개의 정수를 입력 받아서 두수의 차를 절대 값 출력. (두 수의 위치 상관 없이) (if문 이용)
		cout << "과제2. 두 개의 정수를 입력 받아서 두수의 차를 절대 값 출력. (두 수의 위치 상관 없이) (if문 이용)" << endl;
		int lValue{}, rValue{};
		cout << "1번 정수 입력: ";
		cin >> lValue;
		cout << "2번 정수 입력: ";
		cin >> rValue;
		cout << "절대 값: ";
		if (lValue > rValue) cout << lValue - rValue << endl;
		else cout << rValue - lValue << endl;
	}
	{
		// 과제3. 과제2를 삼항연산자를 통해 해결
		cout << "과제3. 과제2를 삼항연산자를 통해 해결" << endl;
		int lValue{}, rValue{};
		cout << "1번 정수 입력: ";
		cin >> lValue;
		cout << "2번 정수 입력: ";
		cin >> rValue;
		cout << "절대 값: ";
		int ret = (lValue > rValue) ? (lValue - rValue) : (rValue - lValue);
		cout << ret << endl;

	}
	{
		// 과제4. 성적표에 학점 추가
		cout << "과제4. 성적표에 학점 추가" << endl;
	
		float korean{}, eng{}, math{};
		float result{}, avg{};

		cout << " -- 국영수 입력 -- " << endl;
		do {
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
		avg = (result / static_cast<float>(NUM_OF_SUBJECT));
		cout << "평균: " << avg << endl;
		cout << "학점: ";
		// 평균 점수 90이상 100 이하 -> A
		// 평균 점수 80이상 90 미만 -> B
		// 평균 점수 70이상 80 미만 -> C
		// 평균 점수 60이상 70 미만 -> D
		// 그 외 F

		if (avg >= 90.0f && avg <= 100.0f) cout << "A" << endl;
		else if (avg >= 80.0f && avg < 90.0f) cout << "B" << endl;
		else if (avg >= 70.0f && avg < 80.0f) cout << "C" << endl;
		else if (avg >= 60.0f && avg < 70.0f) cout << "D" << endl;
		else cout << "F" << endl;
	}

}