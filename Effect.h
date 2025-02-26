#pragma once
struct Effect
{
	bool isAlive;
	int x;
	int y;
	WORD fcolor;
	WORD bcolor;

	int index;
	DWORD indexUpdateTime;
};

void EffectInit();
void EffectUpdate();
void EffectDraw();

void CreateEffect(int x, int y);