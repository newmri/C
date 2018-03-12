#include "Define.h"


void InitCharacter(CharacterInfo src, Character* dest)
{
	memcpy(&dest->m_info, &src, sizeof(src));
}

void CreateCharacter(Character** character, int num)
{
	*character = new Character[num];
}

void DeleteCharacter(Character** character, int num)
{
	if (*character != nullptr) {
		SaveData(*character);
		if (num > 1) delete[] *character;
		else delete *character;
		*character = nullptr;
	}
}

void Move(Character* character, LOCATION dest)
{
	if(character != nullptr) character->m_info.location = dest;
}

bool Attack(Character* from, Character* to)
{
	if (from != nullptr && to != nullptr) {
		int damage{ from->m_info.damage - to->m_info.defense};
		if (damage > 0) to->m_info.hp -= damage;

		if (from->m_info.hp <= 0) {
			to->m_info.exp += from->m_info.exp;
			CheckLevelUp(to);
			Die(from);
			return true;
		}

		if (to->m_info.hp <= 0) {
			from->m_info.exp += to->m_info.exp;
			CheckLevelUp(from);
			Die(to);
			return true;
		}

		return false;
	}

	return false;
}

void Die(Character* character)
{
	if (character != nullptr) {
		SetColor(RED);
		cout << g_chracterName[character->m_info.name] << " is dead now!" << endl;
		if (character->m_info.name == PLAYER) {
			cout << "GAME OVER!" << endl;
			DeleteCharacter(&g_player, 1);
			DeleteCharacter(&g_monster, 1);
			SetColor(WHITE);
			system("pause");
			exit(0);
		}
		SetColor(WHITE);
		system("pause");
		
	}
}

void CheckLevelUp(Character* character)
{
	if (character != nullptr) {
		while (character->m_info.exp >= character->m_info.maxEXP) {
			character->m_info.exp -= character->m_info.maxEXP;
			character->m_info.lvl += 1;
			character->m_info.damage += 5;
			character->m_info.defense += 2;
			character->m_info.maxHP += 5;
			character->m_info.hp = character->m_info.maxHP;
			character->m_info.maxEXP = character->m_info.lvl * 5;
		}

	}
}