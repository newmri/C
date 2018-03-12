#include <iostream>

using namespace std;

enum BEVERAGE { COLA = 1, SPRITE, FANTA, RETURN_MONEY };
enum BEVERAGE_PRICE { COLA_PRICE = 100, SPRITE_PRICE = 200, FANTA_PRICE = 300 };

void SetMoney(int& money);
void ShowMenu(int& money);
bool Update(int& sel, int& money);
bool BuyDrink(BEVERAGE_PRICE price, int& money);

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
	cout << "Input change: ";
	cin >> money;
}
void ShowMenu(int& money)
{
	system("cls");
	cout << "Current Change: " << money << endl;
	cout << "################# Menu #################" << endl;
	cout << "1.Cola(100¿ø) 2.Sprite(200¿ø) 3.Fanta(300¿ø) 4.Return change" << endl;
	cout << "########################################" << endl;
	cout << "Select: ";
}

bool Update(int& sel, int& money)
{
	bool ret{ false };
	cin >> sel;
	switch (sel) {
	case BEVERAGE::COLA:
		ret = BuyDrink(BEVERAGE_PRICE::COLA_PRICE, money); break;
	case BEVERAGE::SPRITE:
		ret = BuyDrink(BEVERAGE_PRICE::SPRITE_PRICE, money); break;
	case BEVERAGE::FANTA:
		ret = BuyDrink(BEVERAGE_PRICE::FANTA_PRICE, money); break;
	case BEVERAGE::RETURN_MONEY: cout << "Current Change: " << money << endl; ret = true; break;
	default: cout << "Error has been occurred!" << endl; break;
	}

	return ret;
}

bool BuyDrink(BEVERAGE_PRICE price, int& money)
{
	if (money >= price) money -= price;
	return false;
}