#include <iostream>
#include "MainGame.h"
#include "Error.h"
using namespace std;

MainGame::MainGame() {
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
	time = 0;
	camera2D.init(width, height);
}

MainGame::~MainGame() {

}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window.create("Hola", width, height, 0);

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Glew not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.002;
	glm::mat4 cameraMatrix = camera2D.getCameraMatrix();
	GLuint pCameraLocation = program.getUniformLocation("pCamera");
	glUniformMatrix4fv(pCameraLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));
	GLuint imageLocation = program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	for (int i = 0; i < sprites.size(); i++)
	{
		sprites.at(i).draw();
	}
	program.unuse();
	//si tengo elementos actualizo
	window.swapWindow();
}

void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				inputManager.setMouseCoords(event.motion.x, event.motion.y);
				break;
			case SDL_KEYUP:
				inputManager.releaseKey(event.key.keysym.sym);
				break;
			case SDL_KEYDOWN:
				inputManager.pressKey(event.key.keysym.sym);
				break;
		}
	}
	handleInput();
}

void MainGame::initShaders() {
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();
}

void MainGame::handleInput()
{
	if (inputManager.isKeyPressed(SDLK_w)) {
		cout << "presionando W" << endl;
		camera2D.setPosition(camera2D.getPosition() + glm::vec2(0.0f, 5.0f));
	}
	if (inputManager.isKeyPressed(SDLK_a)) {
		cout << "presionando A" << endl;
	}
	if (inputManager.isKeyPressed(SDLK_s)) {
		cout << "presionando S" << endl;
	}
	if (inputManager.isKeyPressed(SDLK_d)) {
		cout << "presionando D" << endl;
	}
}

void MainGame::run() {
	init();
	//VERSION CON VECTOR
	sprites.resize(2);
	sprites[0].init(-1, -1, 1, 1, "Textures/mario.png");
	sprites[1].init(0, 0, 1, 1, "Textures/yoshi.png");

	//VERSION CON ARRAY
	/*Sprite sprite1, sprite2;
	sprite1.init(-1, -1, 1, 1, "Textures/mario.png");
	sprite2.init(0, 0, 1, 1, "Textures/yoshi.png");
	sprites[0] = sprite1;
	sprites[1] = sprite2;*/
	update();
}

void MainGame::update() {
	while (gameState != GameState::EXIT) {
		draw();
		processInput();
	}
}