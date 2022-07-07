#pragma once
#include <SDL.h>
#include <string>
#define BOARD_SIZE 3

class Game
{
private:
	SDL_Window* window;
	char **board;
	bool running;
public:
	Game();
	~Game();
	void Init(std::string title, int w, int h);
	void ProcessInput();
	void Update();
	void Render();
	bool IsRunning();
};

