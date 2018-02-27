#include <iostream>
#include <cmath>

using namespace std;

// ##1. Structure
// Set of relative data

struct Player
{
	char name[16];
	int att;
	int hp;
	int exp;
	int lvl;
};

struct Point
{
	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int x, int y) : x(x), y(y) {};

	int x, y;
};

float GetArea(Point& lPos, Point& rPos);
double GetDist(Point& lPos, Point& rPos);

int main()
{
	// ##2. Declare struct variable and init
	Player player; // all member have invaluable value
	Player player2{}; // Set all member 0
	Player player3{ "Warrior", 1, 1, 1, 1 };
	
	// ##3. access member
	cout << player3.name << endl;

	Point lPos{ 0,0 };
	Point rPos{ 10,10 };
	cout << "Area: " << GetArea(lPos, rPos) << endl;
	cout << "Dist: " << GetDist(lPos, rPos) << endl;
	
	// ##4. Structure Pointer
	// address of structure is address of first member 
	cout << &lPos << endl;
	cout << &(lPos.x) << endl;
	cout << &(lPos.y) << endl;

	Point* pos = &lPos;
	(*pos).x = 10;
	cout << lPos.x << endl;
	pos->x = 20;
	cout << lPos.x << endl;
	system("pause");
}

float GetArea(Point& lPos, Point& rPos)
{
	return (rPos.x - lPos.x) * (rPos.y - lPos.y);
}

double GetDist(Point& lPos, Point& rPos)
{
	double w = rPos.x - lPos.x;
	double h = rPos.y - lPos.y;
	return sqrt( (w * w) + (h * h) );
}