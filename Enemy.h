#pragma once
struct Enemy
{
	bool isAlive;
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;
};

void EnemyInit();
void EnemyUpdate();
void EnemyDraw();
	 
void EnemyMove();
void EnemyClipping();

void CreateEnemy(int x, int y);

void BulletEnemyCollision();