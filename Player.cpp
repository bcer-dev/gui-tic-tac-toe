#include "Player.h"

Player::Player(PlayerLetter let, SDL_Renderer *renderer) 
	: letter(let), image(nullptr), renderer(renderer) {}

Player::~Player()
{
	SDL_DestroyTexture(image);
}

void Player::SetImage(std::string filename)
{
	if (image != nullptr)
	{
		SDL_DestroyTexture(image);
	}

	auto sf = SDL_LoadBMP(filename.c_str());
	image = SDL_CreateTextureFromSurface(renderer, sf);
	SDL_FreeSurface(sf);
}

void Player::Render()
{
	for (auto& inst : instances)
	{
		SDL_RenderCopy(renderer, image, NULL, &inst);
	}
}

void Player::Instantiate(int x, int y)
{
	SDL_Rect r;
	r.x = x; r.y = y;
	r.w = SIZE; r.h = SIZE;
	instances.push_back(r);
}
