#pragma once

#include "Enum.h"
#include <string>

struct CharacterInfo
{

	CharacterInfo()
	{
		name = CHARACTER_TYPE_END;
		job = "Null";
		location = LOCATION_END;
		maxHP = 0;
		hp = 0;
		lvl = 0;
		damage = 0;
		defense = 0;
		exp = 0;
	};

	CharacterInfo(CHARACTER_NAME name, std::string job, LOCATION location, int maxHP, int hp, int lvl, int damage, int defense, int exp = 0) :
		name(name), job(job), location(location), maxHP(maxHP), hp(hp), lvl(lvl), damage(damage), defense(defense), exp(exp) {};

	CHARACTER_NAME name;
	std::string job;
	LOCATION location;
	int maxHP, hp, lvl, damage, defense, exp;
};

struct Character
{
	CharacterInfo m_info;
};


void InitCharacter(CharacterInfo src, Character* dest);
void AllocCharacter(Character* character, int num);
void DeAllocCharacter(Character* character, int num);
void Move(Character* character, LOCATION dest);
bool Attack(Character* from, Character* to);
void Die(Character* character);
