#include <iostream>

using namespace std;

void SelectGame();
// 문자열 입력: hello
// 현재 길이: 5
// 결과: olleh
// 길이 구하는 함수는 직접 만들어야함
void PlayReverseString();
void InputString(char* str);
int GetLen(char* str);
void InverseString(char* str, int& len);

// 성적표
// 1. 성적표 입력 2. 전체 출력 3. 검색 4. 종료
//이름
//국어
//영어
//수학
static const unsigned int MAX_STUDENT_NUM = 10;
static const unsigned int NAME_LEN = 10;

void PlayReportCard();
void InputReportCard(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& cnt);
bool CheckError(int& score);
void ShowAll(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& max, int idx);
void ShowStudent(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int idx);
void SearchStudent(char* searchName, char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& max, int idx);
int main()
{
	SelectGame();
}

void SelectGame()
{
	int sel{};
	while (sel != 3) {
		system("cls");
		cout << "1. 문자열 거꾸로 2. 성적표 3. 종료" << endl;
		cout << "선택: ";
		cin >> sel;
		if (sel == 1) PlayReverseString();
		else if (sel == 2) PlayReportCard();

		system("pause");
	}
}

void PlayReverseString()
{
	char str[10]{};
	InputString(str);
}

void InputString(char* str)
{
	cout << "문자열 입력: ";
	cin >> str;
	int len{ GetLen(str) };
	cout << "길이: " << len << endl;
	InverseString(str, len);
	cout << "결과: " << str << endl;
}

int GetLen(char* str)
{
	char ch{};
	int cnt{};
	do {
		ch = str[cnt++];
	}while (ch != '\0');

	return cnt - 1;
}

void InverseString(char* str, int& len)
{
	char tmp{};
	for (int i = 0; i < (len / 2); ++i) {
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}	
}

void PlayReportCard()
{
	char name[MAX_STUDENT_NUM][NAME_LEN]{};
	int kor[MAX_STUDENT_NUM]{}, eng[MAX_STUDENT_NUM]{}, math[MAX_STUDENT_NUM]{},
		total[MAX_STUDENT_NUM]{};
	float avg[MAX_STUDENT_NUM]{};

	int cnt{};
	int sel{};
	char searchName[NAME_LEN];
	while (true) {
		system("cls");
		cout << "1. 성적표 입력(최대 10명) 2. 전체 출력 3. 검색 4. 종료: ";
		cin >> sel;
		switch (sel) {
		case 1: InputReportCard(name, kor, eng, math, total, avg, cnt); break;
		case 2: ShowAll(name, kor, eng, math, total, avg, cnt, cnt); break;
		case 3:
			cout << "이름: ";
			cin >> searchName;
			SearchStudent(searchName, name, kor, eng, math, total, avg, cnt, cnt);
			break;
		default: return;
		}
		system("pause");
	}
}

void InputReportCard(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& cnt)
{
	if (cnt >= MAX_STUDENT_NUM) {
		cout << "입력 불가, 인원 초과!" << endl;
		return;
	}


	cout << "이름: ";
	cin >> name[cnt];
	do {
		cout << "국어: ";
		cin >> kor[cnt];
	} while (CheckError(kor[cnt]));
	do {
	cout << "영어: ";
	cin >> eng[cnt];
	} while (CheckError(eng[cnt]));
	do {
	cout << "수학: ";
	cin >> math[cnt];
	} while (CheckError(eng[cnt]));

	total[cnt] = kor[cnt] + eng[cnt] + math[cnt];
	avg[cnt] = static_cast<float>(total[cnt] / 3.0f);
	++cnt;
}

bool CheckError(int& score)
{
	if (score < 0 || score > 100) {
		cout << "오류! 0 ~ 100 사이의 점수를 입력" << endl;
		return true;
	}
	return false;
}

void ShowAll(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& max, int idx)
{
	if (idx <= 0) return;
	
	ShowAll(name, kor, eng, math, total, avg, max, --idx);
	ShowStudent(name, kor, eng, math, total, avg, idx);
}

void ShowStudent(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int idx)
{
	cout << " ------------ No. " << idx + 1 << " ------------" << endl;
	cout << "이름: " << name[idx] << endl;
	cout << "국어: " << kor[idx] << endl;
	cout << "영어: " << eng[idx] << endl;
	cout << "수학: " << math[idx] << endl;
	cout << "총점: " << total[idx] << endl;
	cout << "평균: " << avg[idx] << endl;
	cout << endl;
}

void SearchStudent(char* searchName, char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& max, int idx)
{
	if (strcmp(searchName, name[idx]) == 0) {
		ShowStudent(name, kor, eng, math, total, avg, idx);
		return;
	}

	if (idx <= 0) {
		cout << "해당 학생 정보가 존재하지 않습니다." << endl;
		return;
	}
	SearchStudent(searchName, name, kor, eng, math, total, avg, max, --idx);

}