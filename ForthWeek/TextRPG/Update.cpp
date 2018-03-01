#include "Define.h"

bool Update()
{
	if (g_player != nullptr) {
		if (g_player->m_info.location == TOWN) PlayerLocationFunc = SelectMainMenu;
		else PlayerLocationFunc = DungeonProcess;
		return PlayerLocationFunc();
	}
	return SelectMainMenu();
}

void ShowCharacterInfo(Character* character)
{
	if (character != nullptr) {
		if (character->m_info.name != PLAYER) cout << endl;
		
		else system("cls");
		
		cout << endl;
		SetColor(GRAY);
		cout << "Name: " << g_chracterName[character->m_info.name] << endl;
		cout << "Job: " << character->m_info.job << endl;
		cout << "Location: " << g_locationName[character->m_info.location] << endl;
		cout << "HP: " << character->m_info.hp << " / " << character->m_info.maxHP << endl;
		cout << "Level: " << character->m_info.lvl << endl;
		cout << "Damage: " << character->m_info.damage << endl;
		cout << "Defense: " << character->m_info.defense << endl;
		cout << "EXP: " << character->m_info.exp << endl;
		cout << endl;
	}

	else system("cls");
}

void ShowMainMenu()
{
	system("cls");
	ShowCharacterInfo(g_player);
	SetColor(RED);
	cout << "---- Main Menu ----" << endl;
	SetColor(BLUE);
	cout << "1. Select Job" << endl;
	SetColor(GREEN);
	cout << "2. Move" << endl;
	SetColor(GRAY);
	cout << "3. Exit Game" << endl;
	SetColor(WHITE);
	cout << "Select: ";
}

bool SelectMainMenu()
{
	int sel{};
	MAIN_MENU mainMenu{ MAIN_MENU_END };
	while (true) {
		ShowMainMenu();
		cin >> sel;
		if (sel > 0 && sel < SEL_EXIT) {
			MainMenuFunc[sel - 1]();
			return true;
		}
		if (sel == SEL_EXIT) return false;
		ShowError();
	}
}

void ShowJobSelectMenu()
{
	ShowCharacterInfo(g_player);
	SetColor(RED);
	cout << "---- Select Job ----" << endl;
	SetColor(GRAY);
	cout << "1. Warrior" << endl;
	cout << "2. Thief" << endl;
	cout << "3. Archer" << endl;
	cout << "4. Magician" << endl;
	cout << "5. Exit" << endl;
	SetColor(WHITE);
	cout << "Select: ";
}

void ShowError()
{
	SetColor(RED);
	cout << "Unknown error has been occurred" << endl;
	SetColor(WHITE);
	system("pause");
}

void SelectJob()
{
	int sel{};
	JOB job{ JOB_END };

	while (true) {
		ShowJobSelectMenu();

		cin >> sel;
		if (sel > 0 && sel < JOB_EIXT) {
			job = static_cast<JOB>(sel);
			if(g_player == nullptr) g_player = new Character;
			//AllocCharacter(g_player, 1);
			break;
		}
		ShowError();
	}


	switch (job) {
	case WARRIOR: InitCharacter(CharacterInfo(PLAYER, "Warrior", TOWN, 130, 130, 1, 10, 10), g_player); break;
	case THIEF: InitCharacter(CharacterInfo(PLAYER, "Thief", TOWN, 80, 80, 1, 15, 5), g_player); break;
	case ARCHER: InitCharacter(CharacterInfo(PLAYER, "Archer", TOWN, 90, 90, 1, 8, 8), g_player); break;
	case MAGICIAN: InitCharacter(CharacterInfo(PLAYER, "Magician", TOWN, 75, 75, 1, 20, 1), g_player); break;
	case JOB_EIXT: break;
	default:
		ShowError();
		break;
	}

}

void ShowMoveMenu()
{
	ShowCharacterInfo(g_player);

	SetColor(RED);
	cout << "---- Select Location ----" << endl;
	SetColor(YELLOW);
	cout << "1. Town" << endl;
	SetColor(GREEN);
	cout << "2. Novice Dungeon" << endl;
	SetColor(SKY);
	cout << "3. Intermediate Dungeon" << endl;
	SetColor(PINK);
	cout << "4. Advanced Dungeon" << endl;
	SetColor(GRAY);
	cout << "5. Exit" << endl;
	SetColor(WHITE);

	cout << "Select: ";
}

void Move()
{
	int sel{};
	while (true) {
		ShowMoveMenu();
		cin >> sel;
		if (sel > 0 && sel <= LOCATION_END) {
			Move(g_player, static_cast<LOCATION>(sel - 1));
			break;
		}
		else if(sel == LOCATION_END + 1) break;
		ShowError();
	}
}

void ShowDungeonMenu()
{
	SetColor(RED);
	cout << "---- Select Behavior ----" << endl;
	SetColor(YELLOW);
	cout << "1. Attack" << endl;
	SetColor(GREEN);
	cout << "2. Run away" << endl;
	SetColor(WHITE);
}

bool DungeonProcess()
{
	if (g_monster == nullptr) g_monster = new Character;
	int lvl{ g_player->m_info.location };
	InitCharacter(CharacterInfo(static_cast<CHARACTER_NAME>(g_player->m_info.location),
		"Warrior", g_player->m_info.location,
		lvl * 100, lvl * 100, lvl, lvl * 15, lvl * 5, lvl * 5), g_monster);

	int sel{};
	while (true) {
		ShowCharacterInfo(g_player);
		ShowCharacterInfo(g_monster);
		ShowDungeonMenu();

		cout << "Select: ";
		cin >> sel;
		if (sel == ATTACK) {
			if (Attack(g_player, g_monster) || Attack(g_monster, g_player)) {
				Move(g_player, TOWN);
				return true;
			}
		}
		
		else if (sel == RUN_AWAY) {
			Move(g_player, TOWN);
			return true;
		}
		else ShowError();
	}
}
