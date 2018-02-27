#include <iostream>

using namespace std;

void SelectGame();
// ���ڿ� �Է�: hello
// ���� ����: 5
// ���: olleh
// ���� ���ϴ� �Լ��� ���� ��������
void PlayReverseString();
void InputString(char* str);
int GetLen(char* str);
void InverseString(char* str, int& len);

// ����ǥ
// 1. ����ǥ �Է� 2. ��ü ��� 3. �˻� 4. ����
//�̸�
//����
//����
//����

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
		cout << "1. ���ڿ� �Ųٷ� 2. ����ǥ 3. ����" << endl;
		cout << "����: ";
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
	cout << "���ڿ� �Է�: ";
	cin >> str;
	int len{ GetLen(str) };
	cout << "����: " << len << endl;
	InverseString(str, len);
	cout << "���: " << str << endl;
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
		cout << "1. ����ǥ �Է�(�ִ� 10��) 2. ��ü ��� 3. �˻� 4. ����: ";
		cin >> sel;
		switch (sel) {
		case 1: InputReportCard(students, cnt); break;
		case 2: ShowAll(students, cnt, cnt); break;
		case 3:
			cout << "�̸�: ";
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
		cout << "�Է� �Ұ�, �ο� �ʰ�!" << endl;
		return;
	}


	cout << "�̸�: ";
	cin >> students[cnt].name;
	do {
		cout << "����: ";
		cin >> students[cnt].kor;
	} while (CheckError(students[cnt].kor));
	do {
		cout << "����: ";
		cin >> students[cnt].eng;
	} while (CheckError(students[cnt].eng));
	do {
		cout << "����: ";
		cin >> students[cnt].math;
	} while (CheckError(students[cnt].eng));

	students[cnt].total = students[cnt].kor + students[cnt].eng + students[cnt].math;
	students[cnt].avg = static_cast<float>(students[cnt].total / 3.0f);
	++cnt;
}

bool CheckError(int& score)
{
	if (score < 0 || score > 100) {
		cout << "����! 0 ~ 100 ������ ������ �Է�" << endl;
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
	cout << "�̸�: " << students[idx].name << endl;
	cout << "����: " << students[idx].kor << endl;
	cout << "����: " << students[idx].eng << endl;
	cout << "����: " << students[idx].math << endl;
	cout << "����: " << students[idx].total << endl;
	cout << "���: " << students[idx].avg << endl;
	cout << endl;
}

void SearchStudent(char* searchName, Student students[], int& max, int idx)
{
	if (strcmp(searchName, students[idx].name) == 0) {
		ShowStudent(students, idx);
		return;
	}

	if (idx <= 0) {
		cout << "�ش� �л� ������ �������� �ʽ��ϴ�." << endl;
		return;
	}
	SearchStudent(searchName, students, max, --idx);

}