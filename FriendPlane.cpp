#include "FriendPlane.h"


const int m_offx=25;//每次按键x位移量
const int m_offy=25;//每次按键y位移量
FriendPlane::FriendPlane(int x, int y)
{
	this->friend_x = x;
	this->friend_y = y;
	::loadimage(friplane_img+0, "./images/me1_1.png");
	::loadimage(friplane_img+1, "./images/me1_2.png");

}

void FriendPlane::drawFriPlane()
{
	::putimage(friend_x, friend_y, friplane_img + 0,SRCPAINT);
	//若只进行下面这一句会看到飞机后面的背景图因此要加上上面一句
	::putimage(friend_x, friend_y, friplane_img + 1, SRCAND);
	
}

void FriendPlane::planeAct(ExMessage& m_msg)
{
	if (Window::hasMessage())
	{
		m_msg = Window::getMessage();
		
		switch (m_msg.vkcode)
		{
		case VK_UP:
			friend_y -= m_offy;
			if (friend_y <= 0)
				friend_y = 0;
			break;
		case VK_DOWN:
			friend_y += m_offy;
			if (friend_y >= (Window::getHeight()-plane_height))
				friend_y = Window::getHeight() - plane_height;
			break;
		case VK_LEFT:
			friend_x -= m_offx;
			if (friend_x <= 0)
				friend_x = 0;
			break;
		case VK_RIGHT:
			friend_x += m_offx;
			if (friend_x >=(Window::getWidth()-plane_width))
				friend_x = Window::getWidth() - plane_width;
			break;
		case VK_SPACE://发射子弹
			//每次射击都会往容器中增加加入两枚子弹，且都处于飞机的中上方
			clip.push_back(Bullet(friend_x + (plane_width / 2) - 5, friend_y - 5));
			clip.push_back(Bullet(friend_x + (plane_width / 2) + 5, friend_y - 5));
			break;
		default:
			break;
		}
	}
}

void FriendPlane::autoFlyBullet()
{
	if (clip.empty())
		return;
	for (auto &val : clip)
	{
		val.bulletMove();
		//超出屏幕则删除该元素
		if (val.getBulletY() < 0)
		{
			vector<Bullet>::iterator pos = find(clip.begin(), clip.end(), val);
			if(pos!=clip.end())
				clip.erase(pos);
		}
	}
}

int FriendPlane::getFrontClip()
{
	return clip.empty()?Window::getHeight():this->clip.front().getBulletY();
}


