#pragma once

#include "Enum.h"
#include "Font.h"

bool Update();
void ShowCharacterInfo(Character* character);
void ShowError();
void ShowMainMenu();
bool SelectMainMenu();
void ShowJobSelectMenu();
void SelectJob();
void ShowMoveMenu();
void Move();
void ShowDungeonMenu();
bool DungeonProcess();


static void(*MainMenuFunc[2])(void) { SelectJob, Move };
static bool(*PlayerLocationFunc)(void);