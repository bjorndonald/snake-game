#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "Game.hpp"

using namespace std;

int main()
{
    Game board = Game();
    board.setup();

    return 0;
}