#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>

enum class GameState {
	PLAY, EXIT
};

class MainGame
{
private:
	int width;
	int height;
	SDL_Window* window;
	void init();
	void processInput();

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

