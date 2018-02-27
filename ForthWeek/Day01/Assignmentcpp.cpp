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

struct Student
{

	Student()
	{
		memset(name, 0, sizeof(name));
		kor = 0;
		eng = 0;
		math = 0;
		total = 0;
		avg = 0;
	}

	Student(char a_name[], int kor, int eng, int math, int total, int avg) :
		kor(kor), eng(eng), math(math), total(total), avg(avg) {
		strcpy_s(name, sizeof(name), a_name);
	};

	char name[NAME_LEN];
	int kor, eng, math, total, avg;

};

void PlayReportCard();
void InputReportCard(Student students[], int& cnt);
bool CheckError(int& score);
void ShowAll(Student students[], int& max, int idx);
void ShowStudent(Student students[], int idx);
void SearchStudent(char* searchName, Student students[], int& max, int idx);

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
	} while (ch != '\0');

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
	Student students[MAX_STUDENT_NUM];

	int cnt{};
	int sel{};
	char searchName[NAME_LEN];
	while (true) {
		system("cls");
		cout << "1. 성적표 입력(최대 10명) 2. 전체 출력 3. 검색 4. 종료: ";
		cin >> sel;
		switch (sel) {
		case 1: InputReportCard(students, cnt); break;
		case 2: ShowAll(students, cnt, cnt); break;
		case 3:
			cout << "이름: ";
			cin >> searchName;
			SearchStudent(searchName, students, cnt, cnt);
			break;
		default: return;
		}
		system("pause");
	}
}

void InputReportCard(Student students[], int& cnt)
{
	if (cnt >= MAX_STUDENT_NUM) {
		cout << "입력 불가, 인원 초과!" << endl;
		return;
	}


	cout << "이름: ";
	cin >> students[cnt].name;
	do {
		cout << "국어: ";
		cin >> students[cnt].kor;
	} while (CheckError(students[cnt].kor));
	do {
		cout << "영어: ";
		cin >> students[cnt].eng;
	} while (CheckError(students[cnt].eng));
	do {
		cout << "수학: ";
		cin >> students[cnt].math;
	} while (CheckError(students[cnt].eng));

	students[cnt].total = students[cnt].kor + students[cnt].eng + students[cnt].math;
	students[cnt].avg = static_cast<float>(students[cnt].total / 3.0f);
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

void ShowAll(Student students[], int& max, int idx)
{
	if (idx <= 0) return;

	ShowAll(students, max, --idx);
	ShowStudent(students, idx);
}

void ShowStudent(Student students[], int idx)
{
	cout << " ------------ No. " << idx + 1 << " ------------" << endl;
	cout << "이름: " << students[idx].name << endl;
	cout << "국어: " << students[idx].kor << endl;
	cout << "영어: " << students[idx].eng << endl;
	cout << "수학: " << students[idx].math << endl;
	cout << "총점: " << students[idx].total << endl;
	cout << "평균: " << students[idx].avg << endl;
	cout << endl;
}

void SearchStudent(char* searchName, Student students[], int& max, int idx)
{
	if (strcmp(searchName, students[idx].name) == 0) {
		ShowStudent(students, idx);
		return;
	}

	if (idx <= 0) {
		cout << "해당 학생 정보가 존재하지 않습니다." << endl;
		return;
	}
	SearchStudent(searchName, students, max, --idx);

}