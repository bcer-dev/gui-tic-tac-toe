#include "Game.h"

int main(int argc, char **argv)
{
    Game game{};
    game.Init("Tic-Tac-Toe", 800, 600);

    while (game.IsRunning())
    {
        game.ProcessInput();
        game.Update();
        game.Render();
    }

    return 0;
}