#pragma once

#include <windows.h>
#include "Enum.h"
#include <string.h>

struct Font
{
	HANDLE outcon;
};

void InitFont();

void SetColor(int color);
