#include "Define.h"

int main()
{
	bool run{ true };

	InitFont();
	while (run) run = Update();
	DeleteCharacter(&g_player, 1);

}