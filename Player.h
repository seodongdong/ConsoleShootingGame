#pragma once
struct Player
{
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;
};

void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

void PlayerMove();
void PlayerClipping();
