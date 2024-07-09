#include "Bullet.h"

const int m_offy = 5;

Bullet::Bullet(int x, int y)
{
	this->bullet_x = x;
	this->bullet_y = y;
	::loadimage(&bullet_img[0], "./images/bullet1_1.png");
	::loadimage(&bullet_img[1], "./images/bullet1_2.png");

}

void Bullet::bulletDraw()
{

	::putimage(bullet_x, bullet_y, &bullet_img[0], SRCPAINT);
	::putimage(bullet_x, bullet_y, &bullet_img[1], SRCAND);

}

int Bullet::getBulletX()
{
	return this->bullet_x;
}

int Bullet::getBulletY()
{
	return this->bullet_y;
}

void Bullet::bulletMove()
{
	this->bullet_y -= m_offy;
	this->bulletDraw();

}

bool Bullet::operator==(const Bullet& b)
{
	if(b.bullet_x==this->bullet_x&&b.bullet_y==this->bullet_y)
		return true;
	return false;
}
