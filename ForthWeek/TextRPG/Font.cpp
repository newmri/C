#include "Define.h"

void InitFont()
{
	g_font.outcon = GetStdHandle(STD_OUTPUT_HANDLE);

}

void SetColor(int color)
{
	SetConsoleTextAttribute(g_font.outcon, color);
}