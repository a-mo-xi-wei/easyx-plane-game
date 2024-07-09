#pragma once
#include"CommonHead.h"
#include"Bullet.h"
#include"Window.h"
#include<algorithm>
const int plane_width = 102;
const int plane_height = 126;//这样定义是因为不知道如何获取图片的相关信息

class FriendPlane
{
public:
	FriendPlane(int x,int y);
	void drawFriPlane();
	void planeAct(ExMessage& m_msg);
	void autoFlyBullet();
	int getFrontClip();
private:
	IMAGE friplane_img[2];
	int friend_x;
	int friend_y;
	ExMessage m_msg;
	vector<Bullet>clip;//会调用一下默认构造函数...
};

