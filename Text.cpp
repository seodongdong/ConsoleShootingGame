#include "include.h"

Text text;
int score;

void TextInit()
{
	text.x = 0;
	text.y = 0;
	text.fColor = WHITE;
	text.bColor = BLACK;
}

void TextUpdate()
{
	sprintf_s(text.str, "SCORE : %d", score);	// ������ ���ڿ��� �ٲ��ش�.
	// strcpy()
}

void TextDraw()
{
	DrawStr(text.x, text.y, text.str, text.fColor, text.bColor);
}
