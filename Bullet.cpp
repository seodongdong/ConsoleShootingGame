#include "include.h"

Bullet bullet[D_BULLET_MAX];

void BulletInit()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		bullet[i].bColor = BLACK;
		bullet[i].fColor = YELLOW;
		bullet[i].body = '|';
		bullet[i].x = 0;
		bullet[i].y = 0;
		bullet[i].isAlive = false;
	}

}

void BulletUpdate()
{
	BulletMove();
	BulletClipping();


}

void BulletDraw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullet[i].isAlive)
		{
			DrawChar(bullet[i].x, bullet[i].y, bullet[i].body, bullet[i].fColor, bullet[i].bColor);
		}

	}

}

void BulletMove()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullet[i].isAlive)
		{
			bullet[i].y--;
		}

	}


}

void BulletClipping()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullet[i].isAlive && bullet[i].y < 0)
		{
			bullet[i].isAlive = false;
		}

	}


}

// 오브젝트 풀링 (Object Pool)
void CreateBullet(int x, int y)
{

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullet[i].isAlive == false)
		{
			bullet[i].x = x;
			bullet[i].y = y;
			bullet[i].isAlive = true;
			break;
		}
	}


}