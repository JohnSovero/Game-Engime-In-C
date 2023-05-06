#include <SDL/SDL.h>
#include "MainGame.h"
#include <time.h>
int main(int argc, char** argv) {
	srand(time(NULL));
	MainGame mainGame;
	mainGame.run();
	system("pause");
	return 0;
}