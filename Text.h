#pragma once
struct Text
{
	int x;
	int y;
	char str[100];
	WORD fColor;
	WORD bColor;
};

void TextInit();
void TextUpdate();
void TextDraw();

extern int score;
// 전역변수로 사용함