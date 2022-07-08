#pragma once

#define SIZE 180

#include <SDL.h>
#include <string>
#include <vector>

enum class PlayerLetter { X, O };

class Player
{
private:
	PlayerLetter letter;
	SDL_Texture* image;
	SDL_Renderer* renderer;
	std::vector<SDL_Rect> instances;
public:
	Player(PlayerLetter let, SDL_Renderer *renderer);
	~Player();
	void SetImage(std::string filename);
	void Render();
	void Instantiate(int x, int y);
};

