#include <iostream>
#include <ctime>

using namespace std;

static unsigned const int NUM = 3;
static unsigned const int BINGO_SIZE = 5;

void PlayBaseBallGame();
void GenerateNumber(int num[]);
void ShowNum(int num[]);
bool UpdateBaseBallGame(int num[]);
void GetarrNum(int num[], int arrNum[]);
void SelectGame();
bool IsOverlapped(int num[], int& target);

void PlayBingGoGame();
void GenerateNumber(int(*arr)[BINGO_SIZE]);
bool IsOverlapped(int(*arr)[BINGO_SIZE], int& target);
void ShowBingoMap(int(*arr)[BINGO_SIZE], int& currentBingo);
void InputBingoIdx(int(*arr)[BINGO_SIZE], int& currentBingo);
void ChangeValueToZero(int& sel, int(*arr)[BINGO_SIZE], int& currentBingo);
void CheckBingo(int(*arr)[BINGO_SIZE], int& currentBingo);

int main()
{
	srand((unsigned int)time(nullptr));
	SelectGame();

	system("pause");
}

void PlayBaseBallGame()
{
	// �߱�����
	// ����: ���� ���� 3��
	// �ߺ����� ���� 3���� �� �Է�:
	// �Է��� ���ڿ� �ڸ��� ������ strike ����, ���ڸ� ������ ball ����
	// 3 strike�� �Ǹ� ���� ����
	int num[NUM]{};
	bool run{ false };
	GenerateNumber(num);
	while (!run) {
		ShowNum(num);
		run = UpdateBaseBallGame(num);
	}

}

void GenerateNumber(int num[])
{
	bool chk{ false };
	int size = NUM;
	while (true) {
		int prizeNum{ rand() % 9 + 1 };
		chk = IsOverlapped(num, prizeNum);
		if (!chk) {
			for (int i = 0; i < NUM; ++i) {
				if (num[i] == 0) {
					num[i] = prizeNum; break;
				}
			}
		}
		if (num[NUM - 1] != 0) return;
	}
}

void ShowNum(int num[])
{
	system("cls");
	cout << "����: ";
	for (int i = 0; i < NUM; ++i) cout << num[i] << " ";
	cout << endl;
}

bool UpdateBaseBallGame(int num[])
{
	int arrNum[NUM]{}, strike{}, ball{};
	GetarrNum(num, arrNum);
	for (int i = 0; i < NUM; ++i) {
		for (int j = 0; j < NUM; ++j) {
			if (arrNum[i] == num[j]) {
				if(i == j) strike++;
				else ball++;
			}
		}
	}
	cout << "strike: " << strike << " ball: " << ball << endl;
	system("pause");
	if (strike == 3) {
		cout << "����� ��!" << endl;
		return true;
	}
	else return false;
}

void GetarrNum(int num[], int arrNum[])
{
	int tmp[NUM]{};
	while (true) {
		bool chk{ false };
		cout << "�ߺ����� �ʴ� ���� 3�� �Է� 1 ~ 9: ";
		for (int i = 0; i < NUM; ++i) cin >> arrNum[i];
		int j = 2;
		for (int i = 2; i >= 0; --i) {
			if (i != 0) {
				tmp[0] = arrNum[i % 2];
				tmp[1] = arrNum[i % 2 + 1];
			}
			else {
				tmp[0] = arrNum[i % 2];
				tmp[1] = arrNum[i % 2 + 2];
			}
			chk = IsOverlapped(tmp, arrNum[j]);
			j = i % 2;
		}
		
		if (!chk) return;
	}
}

bool IsOverlapped(int num[], int& target)
{
	for (int i = 0; i < NUM; ++i) if (num[i] == target) return true;
	return false;
}

void SelectGame()
{
	int sel{};
	while (sel != 3) {
		system("cls");
		cout << "1. �߱����� 2. ���� 3. ����" << endl;
		cout << "����: ";
		cin >> sel;
		if (sel == 1) PlayBaseBallGame();
		else if (sel == 2) PlayBingGoGame();
	}
}

void PlayBingGoGame()
{
	// �������
	// ���� ����: ���� �� (5�Ǹ� ���� ����)
	// ����: 5x5(���� ����)
	// �Է�: ������ ��ȣ
	// ������ ��ȣ�� �Է��ϸ� �ش� slot�� ���ڰ� 0���� �ٲ�� ��
	// ����, ����, �밢���� 0�̸� ���� ����++

	int arr[BINGO_SIZE][BINGO_SIZE]{};
	int currentBingo{};
	bool run{ false };
	GenerateNumber(arr);
	while (currentBingo != 5) ShowBingoMap(arr, currentBingo);
	cout << "�¸�!" << endl;
}

void GenerateNumber(int(*arr)[BINGO_SIZE])
{
	bool chk{ false };
	int size = NUM;
	int bingoNum{};
	while (true) {
		bingoNum = rand() % 45 + 1;
		chk = IsOverlapped(arr, bingoNum);
		if (!chk) {
			for (int i = 0; i < BINGO_SIZE; ++i) {
				for (int j = 0; j < BINGO_SIZE; ++j) {
					if (arr[i][j] == 0) {
						arr[i][j] = bingoNum; goto END;
					}
				}
			}
		}
		END:
		if (arr[BINGO_SIZE - 1][BINGO_SIZE - 1] != 0) return;
	}
}

bool IsOverlapped(int(*arr)[BINGO_SIZE], int& target)
{
	for (int i = 0; i < BINGO_SIZE; ++i) {
		for (int j = 0; j < BINGO_SIZE; ++j) {
			if (arr[i][j] == target) return true;
		}
	}
	return false;
}

void ShowBingoMap(int(*arr)[BINGO_SIZE], int& currentBingo)
{
	system("cls");
	cout << "����: " << currentBingo << endl;
	cout << "-- ���� --" << endl;
	for (int i = 0; i < BINGO_SIZE; ++i) {
		for (int j = 0; j < BINGO_SIZE; ++j) cout << arr[i][j] << " ";
		cout << endl;
	}

	InputBingoIdx(arr, currentBingo);
}

void InputBingoIdx(int(*arr)[BINGO_SIZE], int& currentBingo)
{
	int sel{};
	while (true) {
		cout << "�Է� (1 ~ 25): ";
		cin >> sel;
		if(sel > 25 || sel < 1) continue;
		else break;
	}

	ChangeValueToZero(sel, arr, currentBingo);
	CheckBingo(arr, currentBingo);
	
}

void ChangeValueToZero(int& sel, int(*arr)[BINGO_SIZE], int& currentBingo)
{
	int i{}, j{};
	if ((sel - 5) <= 0) {
		i = 0;
		j = sel - 1;
	}
	else if ((sel - 5) <= 5) {
		i = 1;
		j = (sel - 5) - 1;
	}
	else if ((sel - 5) <= 10) {
		i = 2;
		j = (sel - 10) - 1;
	}
	else if ((sel - 5) <= 15) {
		i = 3;
		j = (sel - 15) - 1;
	}
	else if ((sel - 5) <= 20) {
		i = 4;
		j = (sel - 20) - 1;
	}
	arr[i][j] = 0;

}

void CheckBingo(int(*arr)[BINGO_SIZE], int& currentBingo)
{
	int rowsFlag{};
	int columnFlag{};
	int crossleftFlag{};
	int crossrightFlag{};
	int check{};

	for (int i = 0; i < BINGO_SIZE; ++i) {
		rowsFlag = 0;
		columnFlag = 0;

		for (int j = 0; j < BINGO_SIZE; ++j) {
			if (arr[i][j] == 0) rowsFlag++;
			if (arr[j][i] == 0) columnFlag++;
		}
		// ����üũ
		if (rowsFlag == BINGO_SIZE) check++;
		// ����üũ
		if (columnFlag == BINGO_SIZE) check++;
		
		// �밢�� ���ʿ��� ������
		if (arr[i][i] == 0) crossleftFlag++;
		
		// �밢�� �����ʿ��� ����
		if (arr[BINGO_SIZE - 1 - i][i] == 0) crossrightFlag++;
		
	}

	if (crossleftFlag == BINGO_SIZE) check++;
	if (crossrightFlag == BINGO_SIZE) check++;

	currentBingo = check;
}