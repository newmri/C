#include <iostream>

using namespace std;

enum BEVERAGE { COLAR = 1, SPRITE, FANTA, RETURN_MONEY };
enum BEVERAGE_PRICE { COLAR_PRICE = 100, SPRITE_PRICE = 200, FANTA_PRICE = 300 };
int main()
{
	int readyMoney{}, sel{};
	cout << "�ܵ� �Է�: ";
	cin >> readyMoney;

	while (true) {
		system("cls");
		cout << "���� �ܵ�: " << readyMoney << endl;
		cout << "################# Menu #################" << endl;
		cout << "1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.�ܵ���ȯ" << endl;
		cout << "########################################" << endl;
		cout << "����: ";
		cin >> sel;
		switch (sel) {
		case BEVERAGE::COLAR:
			if (readyMoney - BEVERAGE_PRICE::COLAR_PRICE < 0) break;
			readyMoney -= BEVERAGE_PRICE::COLAR_PRICE; break;
		case BEVERAGE::SPRITE:
			if (readyMoney - BEVERAGE_PRICE::SPRITE_PRICE < 0) break;
			readyMoney -= BEVERAGE_PRICE::SPRITE_PRICE; break;
		case BEVERAGE::FANTA:
			if (readyMoney - BEVERAGE_PRICE::FANTA_PRICE < 0) break;
			readyMoney -= BEVERAGE_PRICE::FANTA_PRICE; break;
		case BEVERAGE::RETURN_MONEY: cout << "���� �Ž�����: " << readyMoney << endl; return 0;
		default: cout << "����!" << endl;
		}

	}

}