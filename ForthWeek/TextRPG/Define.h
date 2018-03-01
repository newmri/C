#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include "Enum.h"
#include "Character.h"
#include "Update.h"
#include "Font.h"

using namespace std;

static Font g_font;
static Character* g_player = nullptr;
static Character* g_monster = nullptr;

static char g_chracterName[CHARACTER_TYPE_END][NAME_LEN]
{
	"Player", "Goblin", "Orc", "Ogre"
};

static char g_locationName[LOCATION_END][NAME_LEN]
{
	"Town", "Novice Dungeon", "Intermediate Dungeon", "Advanced Dungeon"
};

