#pragma once
#include"CommonHead.h"
#include"Window.h"
#include"Bullet.h"
class EnemyPlane
{
public:
	EnemyPlane();
	void drawEnePlane();
	void planeAct();
	int getPlaneY();
	bool operator==(const EnemyPlane& e);
	bool isDestroy();
	void drawBurst();
	void downLife();
private:
	IMAGE eneplane_img[2];
	IMAGE eneplane_down_img[8];
	int enemy_x;
	int enemy_y;
	int enemy_speed;
	int enemy_life;
};

