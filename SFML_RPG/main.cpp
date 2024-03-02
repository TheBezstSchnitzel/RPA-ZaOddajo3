#include"stdafx.h"
#include"Game.h"
#include<Windows.h>

int main(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	
	Game game;

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	game.run();

	//system("pause");
	return 0;
}
