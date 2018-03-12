#pragma once

#include "Enum.h"
#include <string>

#pragma pack(push, 1)
struct CharacterInfo
{

	CharacterInfo()
	{
		name = CHARACTER_TYPE_END;
		job = JOB_END;
		location = LOCATION_END;
		maxHP = 0;
		hp = 0;
		lvl = 0;
		damage = 0;
		defense = 0;
		maxEXP = 0;
		exp = 0;
	};

	CharacterInfo(CHARACTER_NAME name, JOB job, LOCATION location, int maxHP, int hp, int lvl, int damage, int defense, int maxEXP = 5, int exp = 0) :
		name(name), job(job), location(location), maxHP(maxHP), hp(hp), lvl(lvl), damage(damage), defense(defense), maxEXP(maxEXP), exp(exp) {};

	CHARACTER_NAME name;
	JOB job;
	LOCATION location;
	int maxHP, hp, lvl, damage, defense, maxEXP, exp;
};
#pragma pack(pop)


struct Character
{
	CharacterInfo m_info;
};

void InitCharacter(CharacterInfo src, Character* dest);
void CreateCharacter(Character** character, int num);
void DeleteCharacter(Character** character, int num);
void Move(Character* character, LOCATION dest);
bool Attack(Character* from, Character* to);
void Die(Character* character);
void CheckLevelUp(Character* character);
