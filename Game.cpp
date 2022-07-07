#include "Game.h"
#include <iostream>

Game::Game() : running(false), window(nullptr), board(new char*[BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		board[i] = new char[BOARD_SIZE];
		memset(board[i], '-', BOARD_SIZE);
	}
}

Game::~Game()
{
	SDL_DestroyWindow(window);

	for (int i = 0; i < BOARD_SIZE; i++)
		delete[] board[i];
	delete[] board;

	SDL_Quit();
}

void Game::Init(std::string title, int w, int h)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << SDL_GetError() << '\n';
		return;
	}

	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		w, h,
		SDL_WINDOW_SHOWN
	);

	if (window == nullptr)
	{
		std::cerr << SDL_GetError() << '\n';
		return;
	}

	running = true;
}

void Game::ProcessInput()
{
	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	default:
		break;
	}
}

void Game::Update()
{
}

void Game::Render()
{
}

bool Game::IsRunning()
{
	return running;
}
