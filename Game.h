#pragma once
#include"CommonHead.h"
#include"Window.h"
#include"FriendPlane.h"
#include"EnemyPlane.h"
#include <chrono>
class Game
{
public:
	Game();
	void run();
	bool IsGameover();
	void drawBackground();
	void showEplane();
	void isHit();
private:
	IMAGE m_bk1;
	IMAGE m_bk2;//两张图片实现滚动效果
	int bk1_x;
	int bk1_y;
	int bk2_x;
	int bk2_y;
	ExMessage m_msg;
	bool m_Destroy;
	FriendPlane* fplane;
	vector<EnemyPlane>eplanes;//存放敌机，令每次出场一架敌机
};

