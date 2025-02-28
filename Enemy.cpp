#include "include.h"

Enemy enemys[D_ENEMY_MAX];
DWORD createEnemyTime;

//int frameCount = 0;
//int frameInterval = 5;

void EnemyInit()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		enemys[i].bColor = RED;
		enemys[i].fColor = RED;
		enemys[i].body = ' ';
		enemys[i].x = 0;
		enemys[i].y = 0;
		enemys[i].isAlive = false;
	}
}

void EnemyUpdate()
{
	//frameCount++;
	//
	//if (frameCount >= frameInterval)
	//{
	//	CreateEnemy();
	//	frameCount = 0;
	//}

	// 1000 = 1초
	if (GetTickCount() > createEnemyTime)
	{
		// 20시 10분 0.5초 
		createEnemyTime = GetTickCount() + 300;
		CreateEnemy(rand() % 120, -1);
	}
	
	EnemyMove();
	EnemyClipping();

}

void EnemyDraw()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive)	//살아있는 적만 그림
		{
			DrawChar(enemys[i].x, enemys[i].y, enemys[i].body, enemys[i].fColor, enemys[i].bColor);
		}
	}
}

void EnemyMove()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive)	//살아있는 적만 움직임
		{
			enemys[i].y++;	//y좌표 증가 (내려오기)
		}
	}
}

void EnemyClipping()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive && enemys[i].y >= 30)	//화면 밖을 벗어나면 적이 죽음
		{
			enemys[i].isAlive = false;	//적이 화면 밖으로 나가면 다시 죽음 상태로 처리
		}

	}
}

// 자동으로 만들 때 x값을 랜덤으로 해야함
// x값 = 0 ~ 119 / y값 = -1 ~ 0
void CreateEnemy(int x, int y)
{
	//int enemyCount = rand() % 10;

	//int x = rand() % 120;
	//int y = -1;

	for (int i = 0; i < D_ENEMY_MAX/*&& enemyCount > 0*/; i++)
	{
		if (enemys[i].isAlive == false)
		{
			enemys[i].x = x;
			enemys[i].y = y;
			enemys[i].isAlive = true;
			break;
			//enemyCount--;
		}
	}
}

void BulletEnemyCollision()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullet[i].isAlive)
		{
			for (int j = 0; j < D_ENEMY_MAX; j++)
			{
				if (enemys[j].isAlive)
				{
					if (bullet[i].x == enemys[j].x && (bullet[i].y && enemys[j].y || bullet[i].y - 1 == enemys[j].y))
					{
						score++;
						bullet[i].isAlive = false;
						enemys[j].isAlive = false;
						CreateEffect(enemys[j].x, enemys[j].y);
						break;
					}
				}
				
			}
		}

	}

}
