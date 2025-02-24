#include "include.h"
#include "stdlib.h"
#include "time.h"

Enemy enemys[D_ENEMY_MAX];
int frameCount = 0;
int frameInterval = 5;

void EnemyInit()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		enemys[i].bColor = BLACK;
		enemys[i].fColor = RED;
		enemys[i].body = '��';
		enemys[i].x = 0;
		enemys[i].y = 0;
		enemys[i].isAlive = false;
	}
}

void EnemyUpdate()
{
	frameCount++;
	
	if (frameCount >= frameInterval)
	{
		CreateEnemy();
		frameCount = 0;
	}

	EnemyMove();
	EnemyClipping();
}

void EnemyDraw()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive)	//����ִ� ���� �׸�
		{
			DrawChar(enemys[i].x, enemys[i].y, enemys[i].body, enemys[i].fColor, enemys[i].bColor);
		}
	}
}

void EnemyMove()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive)	//����ִ� ���� ������
		{
			enemys[i].y++;	//y��ǥ ���� (��������)
		}
	}
}

void EnemyClipping()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive && enemys[i].y >= 30)	//ȭ�� ���� ����� ���� ����
		{
			enemys[i].isAlive = false;	//���� ȭ�� ������ ������ �ٽ� ���� ���·� ó��
		}

	}
}

// �ڵ����� ���� �� x���� �������� �ؾ���
// x�� = 0 ~ 119 / y�� = -1 ~ 0
void CreateEnemy()
{
	int enemyCount = rand() % 10;

	int x = rand() % 120;
	int y = -1;

	for (int i = 0; i < D_ENEMY_MAX && enemyCount > 0; i++)
	{
		if (enemys[i].isAlive == false)
		{
			enemys[i].x = x;
			enemys[i].y = y;
			enemys[i].isAlive = true;
			enemyCount--;
		}
	}
}
