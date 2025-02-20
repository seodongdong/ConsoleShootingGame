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
	// 0,0(������) ~ 119, 29(�����ʾƷ�)
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
	// �Ѿ� ���� -> �����̽�Ű(VK_SPACE)�� ������ �÷��̾� ��ġ�� �Ѿ� ����
	// �Ѿ��� ���� �̵�(�ڵ����� ��� ���� �ö�)

	if (player.x < 0)
		player.x = 0;

	if (player.x > 119)
		player.x = 119;

	if (player.y < 0)
		player.y = 0;

	if (player.y > 29)
		player.y = 29;


}