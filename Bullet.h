#pragma once
struct Bullet
{
	bool isAlive;		// true = 사용 중인 상태, false = 미사용 (대기 상태)
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;
};

void BulletInit();
void BulletUpdate();
void BulletDraw();

void BulletMove();
void BulletClipping();

void CreateBullet(int x, int y);

extern Bullet bullet[D_BULLET_MAX];
// 전역변수가 있음을 알리는 것.