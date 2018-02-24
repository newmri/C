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
		cout << "1. ����ǥ �Է�(�ִ� 10��) 2. ��ü ��� 3. �˻� 4. ����: ";
		cin >> sel;
		switch (sel) {
		case 1: InputReportCard(name, kor, eng, math, total, avg, cnt); break;
		case 2: ShowAll(name, kor, eng, math, total, avg, cnt, cnt); break;
		case 3:
			cout << "�̸�: ";
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
		cout << "�Է� �Ұ�, �ο� �ʰ�!" << endl;
		return;
	}


	cout << "�̸�: ";
	cin >> name[cnt];
	do {
		cout << "����: ";
		cin >> kor[cnt];
	} while (CheckError(kor[cnt]));
	do {
	cout << "����: ";
	cin >> eng[cnt];
	} while (CheckError(eng[cnt]));
	do {
	cout << "����: ";
	cin >> math[cnt];
	} while (CheckError(eng[cnt]));

	total[cnt] = kor[cnt] + eng[cnt] + math[cnt];
	avg[cnt] = static_cast<float>(total[cnt] / 3.0f);
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

void ShowAll(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& max, int idx)
{
	if (idx <= 0) return;
	
	ShowAll(name, kor, eng, math, total, avg, max, --idx);
	ShowStudent(name, kor, eng, math, total, avg, idx);
}

void ShowStudent(char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int idx)
{
	cout << " ------------ No. " << idx + 1 << " ------------" << endl;
	cout << "�̸�: " << name[idx] << endl;
	cout << "����: " << kor[idx] << endl;
	cout << "����: " << eng[idx] << endl;
	cout << "����: " << math[idx] << endl;
	cout << "����: " << total[idx] << endl;
	cout << "���: " << avg[idx] << endl;
	cout << endl;
}

void SearchStudent(char* searchName, char(*name)[MAX_STUDENT_NUM], int kor[], int eng[], int math[], int total[], float avg[], int& max, int idx)
{
	if (strcmp(searchName, name[idx]) == 0) {
		ShowStudent(name, kor, eng, math, total, avg, idx);
		return;
	}

	if (idx <= 0) {
		cout << "�ش� �л� ������ �������� �ʽ��ϴ�." << endl;
		return;
	}
	SearchStudent(searchName, name, kor, eng, math, total, avg, max, --idx);

}