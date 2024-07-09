#include "EnemyPlane.h"
default_random_engine eng((unsigned int)time(0));

EnemyPlane::EnemyPlane()
{
	
	uniform_int_distribution<int>u_type(1, 3);
	this->enemy_y = -1000;
	int type = u_type(eng);
	if (type == 1)
	{
		this->enemy_life = 10;
		uniform_int_distribution<int>u_x(0, Window::getWidth() - 57);
		this->enemy_x = u_x(eng);
		::loadimage(eneplane_img + 0, "./images/enemy1_1.png");
		::loadimage(eneplane_img + 1, "./images/enemy1_2.png");
		::loadimage(eneplane_down_img + 0, "./images/enemy1_down1_1.png");
		::loadimage(eneplane_down_img + 1, "./images/enemy1_down1_2.png");
		::loadimage(eneplane_down_img + 2, "./images/enemy1_down2_1.png");
		::loadimage(eneplane_down_img + 3, "./images/enemy1_down2_2.png");
		::loadimage(eneplane_down_img + 4, "./images/enemy1_down3_1.png");
		::loadimage(eneplane_down_img + 5, "./images/enemy1_down3_2.png");
		::loadimage(eneplane_down_img + 6, "./images/enemy1_down4_1.png");
		::loadimage(eneplane_down_img + 7, "./images/enemy1_down4_2.png");
	}
	else if (type == 2)
	{
		this->enemy_life = 50;
		uniform_int_distribution<int>u_x(0, Window::getWidth() - 69);
		this->enemy_x = u_x(eng);
		::loadimage(eneplane_img + 0, "./images/enemy2_1.png");
		::loadimage(eneplane_img + 1, "./images/enemy2_2.png");
	}
	else
	{
		this->enemy_life = 100;
		uniform_int_distribution<int>u_x(0, Window::getWidth() - 169);
		this->enemy_x = u_x(eng);
		::loadimage(eneplane_img + 0, "./images/enemy3_1.png");
		::loadimage(eneplane_img + 1, "./images/enemy3_2.png");
	}
}

void EnemyPlane::drawEnePlane()
{
	::putimage(enemy_x, enemy_y, eneplane_img + 0, SRCPAINT);
	//若只进行下面这一句会看到飞机后面的背景图因此要加上上面一句
	::putimage(enemy_x, enemy_y, eneplane_img + 1, SRCAND);
}

void EnemyPlane::planeAct()
{
	uniform_int_distribution<int>u_speed(1, 3);
	this->enemy_y += u_speed(eng);
}

int EnemyPlane::getPlaneY()
{
	return this->enemy_y;
}

bool EnemyPlane::operator==(const EnemyPlane& e)
{
	if (e.enemy_x == this->enemy_x && e.enemy_y == this->enemy_y)
		return true;
	return false;
}

bool EnemyPlane::isDestroy()
{
	if (this->enemy_life <= 0)
		return true;
	return false;
}

void EnemyPlane::drawBurst()
{
	Sleep(10);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 0, SRCPAINT);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 1, SRCAND);
	Sleep(10);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 2, SRCPAINT);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 3, SRCAND);
	Sleep(10);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 4, SRCPAINT);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 5, SRCAND);
	Sleep(10);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 6, SRCPAINT);
	::putimage(enemy_x, enemy_y, eneplane_down_img + 7, SRCAND);
}

void EnemyPlane::downLife()
{
	this->enemy_life -= 2;
}
