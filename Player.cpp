#include "include.h"
Player player;
void PlayerInit()
{
	player.bColor = BLACK;
	player.fColor = WHITE;
	player.x = 60;
	player.y = 15;
	player.body = 'A';

	bullet[D_BULLET_MAX].x = 0;
	bullet[D_BULLET_MAX].y = 0;
	bullet[D_BULLET_MAX].isAlive = false;
}

void PlayerUpdate()
{
	PlayerMove();
	PlayerClipping();

	if (GetAsyncKeyState(VK_SPACE))
	{
		//if (bullet.x != player.x || bullet.y != player.y)
		//{
		//	for (int i = bullet.x; i < player.x; i++)
		//	{
		//		for (int i = bullet.y; i < player.y; i++)
		//		{
		//			bullet.y++;
		//		}
		//		bullet.x++;
		//	}
		//}
		CreateBullet(player.x, player.y);
	}
}

void PlayerDraw()
{
	DrawChar(player.x, player.y, player.body, player.fColor, player.bColor);
}

void PlayerMove()
{
	// 0,0(왼쪽위) ~ 119, 29(오른쪽아래)
	if (GetAsyncKeyState('W'))
		player.y--;

	if (GetAsyncKeyState('A'))
		player.x--;

	if (GetAsyncKeyState('S'))
		player.y++;

	if (GetAsyncKeyState('D'))
		player.x++;


}

void PlayerClipping()
{
	// 총알 제작 -> 스페이스키(VK_SPACE)를 누르면 플레이어 위치에 총알 생성
	// 총알은 위로 이동(자동으로 계속 위로 올라감)

	if (player.x < 0)
		player.x = 0;

	if (player.x > 119)
		player.x = 119;

	if (player.y < 0)
		player.y = 0;

	if (player.y > 29)
		player.y = 29;


}