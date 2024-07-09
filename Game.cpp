#include "Game.h"
const int bk_move_speed = 5;

Game::Game()
{
    //初始化
    m_Destroy = false;
    bk1_x = 0;
    bk1_y = 0;
    bk2_x = 0;
    bk2_y = Window::getHeight();
    ::loadimage(&m_bk1, "./images/background.png", Window::getWidth(), Window::getHeight());
    ::loadimage(&m_bk2, "./images/background.png", Window::getWidth(), Window::getHeight());
    int plane_x = (Window::getWidth() - plane_width) / 2;
    int plane_y = Window::getHeight() - plane_height;
    fplane = new FriendPlane(plane_x,plane_y);
}

void Game::run()
{
    Window::beginDraw();
    // 计时器变量
    static auto startTime = chrono::steady_clock::now();
    while (true)
    {
        // 获取当前时间点
        auto currentTime = chrono::steady_clock::now();

        // 计算时间差，单位为秒
        chrono::duration<double> elapsedTime = currentTime - startTime;
        double elapsedSeconds = elapsedTime.count();
        //if (elapsedSeconds >= 1.0)
        //{
        //    eplanes.push_back(EnemyPlane());
        //    // 重置计时器
        //    startTime = currentTime;
        //}
        Window::clearBackground();
        //1.实现背景滚动效果
        drawBackground();
        //this->showEplane();
        fplane->drawFriPlane();
        fplane->planeAct(m_msg);
        fplane->autoFlyBullet();
        //this->isHit();
        Window::flushDraw();
        Sleep(3);
    }
   Window::endDraw();
}

bool Game::IsGameover()
{
    if(m_Destroy==true)
        return true;
    return false;
}

void Game::drawBackground()
{
    ::putimage(bk1_x, bk1_y, &m_bk1);
    ::putimage(bk2_x, bk2_y, &m_bk2);
    bk1_y -= bk_move_speed;
    bk2_y -= bk_move_speed; 
    if (bk1_y <= -Window::getHeight())
        bk1_y = Window::getHeight();
    if(bk2_y<=-Window::getHeight())
        bk2_y = Window::getHeight();

}

void Game::showEplane()
{
    
    for (auto& val : eplanes)
    {
        val.drawEnePlane();
        val.planeAct();
        //超出屏幕则删除该元素
        if (val.getPlaneY()>Window::getHeight())
        {
            vector<EnemyPlane>::iterator pos = find(eplanes.begin(), eplanes.end(), val);
            if (pos != eplanes.end())
                eplanes.erase(pos);
        }

    }
}

void Game::isHit()
{
    for (auto &val : eplanes)
    {
        if (val.getPlaneY() >= this->fplane->getFrontClip())
            val.downLife();
        if (val.isDestroy())
            val.drawBurst();
    }
}

