#include "Define.h"


void InitCharacter(CharacterInfo src, Character* dest)
{
	memcpy(&dest->m_info, &src, sizeof(src));
}

void AllocCharacter(Character* character, int num)
{
	if (character != nullptr) character = new Character[num]{};
}

void DeAllocCharacter(Character* character, int num)
{
	if (character != nullptr) {
		if (num > 1) delete[] character;
		else delete character;
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
			Die(from);
			return true;
		}

		if (to->m_info.hp <= 0) {
			from->m_info.exp += to->m_info.exp;
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
			DeAllocCharacter(g_player, 1);
			DeAllocCharacter(g_monster, 1);
			SetColor(WHITE);
			system("pause");
			exit(0);
		}
		SetColor(WHITE);
		system("pause");
		
	}
}

