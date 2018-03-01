#include <iostream>

using namespace std;

// ##1. enumeration

enum STANCE { IDLE, ATTACK, DEFENSE };


int main()
{
	STANCE stance{ IDLE }; // OK
	//stance = 4; // Error
	//stance = 0; // Error

	switch (stance) {
	case IDLE: break;
	case ATTACK: break;
	case DEFENSE: break;
	default: while (true);
	}

}