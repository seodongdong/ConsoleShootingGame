#include "include.h"
Effect effects[D_EFFECT_MAX];

//3차원 배열 값 초기화
char effectBody[3][3][3] =
{
	{
		{' ', ' ', ' '},
		{' ', '*', ' '},
		{' ', ' ', ' '}
	},

		{
		{' ', '*', ' '},
		{'*', '*', '*'},
		{' ', '*', ' '}
	},

		{
		{'*', ' ', '*'},
		{' ', '*', ' '},
		{'*', ' ', '*'}
	}
};

void EffectInit()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		effects[i].isAlive = false;
		effects[i].x = 0;;
		effects[i].y = 0;
		effects[i].fcolor = YELLOW;
		effects[i].bcolor = BLACK;

		effects[i].index = 0;
		effects[i].indexUpdateTime = 0;
	}

}

void EffectUpdate()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effects[i].isAlive && effects[i].indexUpdateTime < GetTickCount())
		{
			effects[i].index++;
			effects[i].indexUpdateTime = GetTickCount() + 300;
			
			if (effects[i].index >= 3)
			{
				effects[i].isAlive = false;
			}
		}

	}

	EffectDraw();
}

void EffectDraw()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effects[i].isAlive)
		{
			DrawChar(effects[i].x - 1, effects[i].y - 1, effectBody[effects[i].index][0][0], effects[i].fcolor, effects[i].bcolor);
			DrawChar(effects[i].x, effects[i].y - 1, effectBody[effects[i].index][0][1], effects[i].fcolor, effects[i].bcolor);
			DrawChar(effects[i].x + 1, effects[i].y - 1, effectBody[effects[i].index][0][2], effects[i].fcolor, effects[i].bcolor);

			DrawChar(effects[i].x - 1, effects[i].y, effectBody[effects[i].index][1][0], effects[i].fcolor, effects[i].bcolor);
			DrawChar(effects[i].x, effects[i].y, effectBody[effects[i].index][1][1], effects[i].fcolor, effects[i].bcolor);
			DrawChar(effects[i].x + 1, effects[i].y, effectBody[effects[i].index][1][2], effects[i].fcolor, effects[i].bcolor);

			DrawChar(effects[i].x - 1, effects[i].y + 1, effectBody[effects[i].index][2][0], effects[i].fcolor, effects[i].bcolor);
			DrawChar(effects[i].x, effects[i].y + 1, effectBody[effects[i].index][2][1], effects[i].fcolor, effects[i].bcolor);
			DrawChar(effects[i].x + 1, effects[i].y + 1, effectBody[effects[i].index][2][2], effects[i].fcolor, effects[i].bcolor);
		}

	}
}

void CreateEffect(int x, int y)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effects[i].isAlive == false)
		{
			effects[i].isAlive = true;
			effects[i].x = x;
			effects[i].y = y;
			effects[i].index = 0;            // 첫 번째 단계부터 시작
			effects[i].indexUpdateTime = GetTickCount() + 300;  // 현재 시간값
			break;
		}
	}
}
