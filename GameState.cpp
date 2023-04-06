#include "GameState.hpp"

int GameState::getStep() const
{
    return step;
}

int GameState::getDirection() const
{
    return direction;
}

GameState::GameState(int &direction, int &step) : direction(direction), step(step)
{
}

GameState::~GameState()
{
}