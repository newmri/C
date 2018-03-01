#include "Define.h"

int main()
{
	bool run{ true };

	InitFont();

	while (run) run = Update();
	DeAllocCharacter(g_player, 1);
	

}