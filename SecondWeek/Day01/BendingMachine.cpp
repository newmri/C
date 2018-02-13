#include <iostream>

using namespace std;

enum BEVERAGE { COLAR = 1, SPRITE, FANTA, RETURN_MONEY };
enum BEVERAGE_PRICE { COLAR_PRICE = 100, SPRITE_PRICE = 200, FANTA_PRICE = 300 };
int main()
{
	int readyMoney{}, sel{};
	cout << "ÀÜµ· ÀÔ·Â: ";
	cin >> readyMoney;

	while (true) {
		system("cls");
		cout << "ÇöÀç ÀÜµ·: " << readyMoney << endl;
		cout << "################# Menu #################" << endl;
		cout << "1.ÄÝ¶ó(100¿ø) 2.»çÀÌ´Ù(200¿ø) 3.È¯Å¸(300¿ø) 4.ÀÜµ·¹ÝÈ¯" << endl;
		cout << "########################################" << endl;
		cout << "¼±ÅÃ: ";
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
		case BEVERAGE::RETURN_MONEY: cout << "ÇöÀç °Å½º¸§µ·: " << readyMoney << endl; return 0;
		default: cout << "¿À·ù!" << endl;
		}

	}

}