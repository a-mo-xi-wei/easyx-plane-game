#pragma once
#include"CommonHead.h"
class Bullet
{
public:
	 Bullet() {};
	Bullet(int x, int y);
	void bulletDraw();
	int getBulletX();
	int getBulletY();
	void bulletMove();
	bool operator==(const Bullet& b);
private:
	int power = 5;
	int bullet_x;
	int bullet_y;
	IMAGE bullet_img[2];
};

