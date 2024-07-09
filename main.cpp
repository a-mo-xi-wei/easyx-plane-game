#include"Window.h"
#include"Game.h"
const int WindowWidth = 480;
const int WindowHeight = 700;

int main()
{
	Window w(WindowWidth, WindowHeight, EX_NOMINIMIZE);
	w.setWindowTitle("飞机大战");
	Game game;
	game.run();
	system("pause");
	closegraph();
	return 0;
}