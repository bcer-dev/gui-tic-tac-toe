#include "Game.h"
#include <iostream>

// Todo: use SDL_ShowSimpleMessageBox(0, "Test", "Hello", window); to show winner

bool Game::HasWinner()
{
	return false;
}

Game::Game() 
	: running(false), window(nullptr), renderer(nullptr), board_img(nullptr), board(new char* [BOARD_SIZE])
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

	SDL_DestroyTexture(board_img);
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
	if (!window)
	{
		std::cerr << SDL_GetError() << '\n';
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		std::cerr << SDL_GetError() << '\n';
		return;
	}

	SDL_Surface* img_sf = SDL_LoadBMP("Assets/Grid.bmp");
	if (!img_sf)
	{
		std::cerr << SDL_GetError() << '\n';
		return;
	}

	board_img = SDL_CreateTextureFromSurface(renderer, img_sf);
	SDL_FreeSurface(img_sf);

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
	case SDL_MOUSEBUTTONDOWN:
		SDL_ShowSimpleMessageBox(0, "ALERT", "YOU CLICKED!!!", window);
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
	SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 0xff);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, board_img, NULL, NULL);
	SDL_RenderPresent(renderer);
}

bool Game::IsRunning()
{
	return running;
}
