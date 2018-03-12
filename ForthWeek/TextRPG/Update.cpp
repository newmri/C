#include "Define.h"

bool Update()
{
	if (g_player != nullptr) {
		if (g_player->m_info.location == TOWN) PlayerLocationFunc = SelectMainMenu;
		else PlayerLocationFunc = DungeonProcess;
		return PlayerLocationFunc();
	}

	else LoadData(&g_player);
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
		cout << "Job: " << g_jobName[character->m_info.job] << endl;
		cout << "Location: " << g_locationName[character->m_info.location] << endl;
		cout << "HP: " << character->m_info.hp << " / " << character->m_info.maxHP << endl;
		cout << "Level: " << character->m_info.lvl << endl;
		cout << "Damage: " << character->m_info.damage << endl;
		cout << "Defense: " << character->m_info.defense << endl;
		if (character->m_info.name == PLAYER) cout << "EXP: " << character->m_info.exp << " / " << character->m_info.maxEXP << endl;
		else cout << "EXP: " << character->m_info.exp << endl;
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
		if (sel == SEL_EXIT) {
			SaveData(g_player);
			DeleteCharacter(&g_player, 1);
			exit(1);
		}
		ShowError();
	}
}

void ShowJobSelectMenu()
{
	ShowCharacterInfo(g_player);
	SetColor(RED);
	cout << "---- Select Job ----" << endl;
	SetColor(GRAY);
	for (int i = 0; i < JOB_EXIT - 1; ++i) cout << i + 1 << ". " << g_jobName[i] << endl;
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
	JOB job = JOB_END;

	while (true) {
		ShowJobSelectMenu();

		cin >> sel;
		if (sel > 0 && sel <= JOB_EXIT) {
			job = static_cast<JOB>(sel);
			CreateCharacter(&g_player, 1);
			break;
		}
		ShowError();
	}


	switch (job) {
	case WARRIOR: InitCharacter(CharacterInfo(PLAYER, WARRIOR, TOWN, 130, 130, 1, 10, 10), g_player); break;
	case THIEF: InitCharacter(CharacterInfo(PLAYER, THIEF, TOWN, 80, 80, 1, 15, 5), g_player); break;
	case ARCHER: InitCharacter(CharacterInfo(PLAYER, ARCHER, TOWN, 90, 90, 1, 8, 8), g_player); break;
	case MAGICIAN: InitCharacter(CharacterInfo(PLAYER, MAGICIAN, TOWN, 75, 75, 3, 25, 1), g_player); break;
	case JOB_EXIT: break;
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
	CreateCharacter(&g_monster, 1);
	int lvl{ g_player->m_info.location };
	InitCharacter(CharacterInfo(static_cast<CHARACTER_NAME>(g_player->m_info.location),
		WARRIOR, g_player->m_info.location,
		lvl * 100, lvl * 100, lvl, lvl * 15, lvl * 5, lvl * 5, lvl * 7), g_monster);

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

void SaveData(Character* character)
{
	if (character != nullptr) {
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, "../DB/SaveFile.db", "wb");
		if (err == 0) {
				
			fwrite(&character->m_info, sizeof(character->m_info), 1, fp);
			fclose(fp);
		}
	}
}

void LoadData(Character** character)
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../DB/SaveFile.db", "rb");
	if (err == 0) {
		CreateCharacter(character, 1);
		CharacterInfo info;
		fread(&info, sizeof(info), 1, fp);
		InitCharacter(info, *character);
		fclose(fp);
	}

	return;
}