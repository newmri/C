#pragma once

enum JOB { WARRIOR = 1, THIEF, ARCHER, MAGICIAN, JOB_EXIT, JOB_END };
enum CHARACTER_NAME { PLAYER, GOBLIN, ORC, OGRE, CHARACTER_TYPE_END };
enum LOCATION { TOWN, NOVICE_DUNGEON, INTERMEDIATE_DUNGEON, ADVANCED_DUNGEON, LOCATION_END };
enum FONT_COLOR { GRAY = 8, BLUE, GREEN, SKY, RED, PINK, YELLOW, WHITE };
enum MAIN_MENU { SEL_JOB = 1, SEL_MOVE, SEL_EXIT, MAIN_MENU_END };
enum DUNGEON_MENU { ATTACK = 1, RUN_AWAY, DUNGEON_MENU_END };

static const int NAME_LEN = 64;
