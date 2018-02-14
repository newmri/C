#include <iostream>

using namespace std;

enum BEVERAGE { COLAR = 1, SPRITE, FANTA, RETURN_MONEY };
enum BEVERAGE_PRICE { COLAR_PRICE = 100, SPRITE_PRICE = 200, FANTA_PRICE = 300 };

void SetMoney(int& money);
void ShowMenu(int& money);
bool Update(int& sel, int& money);

int main()
{
	int readyMoney{}, sel{}, running{ false };
	SetMoney(readyMoney);

	while (!running) {
		ShowMenu(readyMoney);
		running = Update(sel, readyMoney);
	}

}

void SetMoney(int& money)
{
	cout << "�ܵ� �Է�: ";
	cin >> money;
}
void ShowMenu(int& money)
{
	system("cls");
	cout << "���� �ܵ�: " << money << endl;
	cout << "################# Menu #################" << endl;
	cout << "1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.�ܵ���ȯ" << endl;
	cout << "########################################" << endl;
	cout << "����: ";
}

bool Update(int& sel, int& money)
{
	bool ret{ false };
	cin >> sel;
	switch (sel) {
	case BEVERAGE::COLAR:
		if (money - BEVERAGE_PRICE::COLAR_PRICE < 0) break;
		money -= BEVERAGE_PRICE::COLAR_PRICE; break;
	case BEVERAGE::SPRITE:
		if (money - BEVERAGE_PRICE::SPRITE_PRICE < 0) break;
		money -= BEVERAGE_PRICE::SPRITE_PRICE; break;
	case BEVERAGE::FANTA:
		if (money - BEVERAGE_PRICE::FANTA_PRICE < 0) break;
		money -= BEVERAGE_PRICE::FANTA_PRICE; break;
	case BEVERAGE::RETURN_MONEY: cout << "���� �Ž�����: " << money << endl; ret = true; break;
	default: cout << "����!" << endl; break;
	}

	return ret;
}