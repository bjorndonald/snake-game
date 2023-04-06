#include "Instructions.hpp"
#include "GameState.hpp"

GameState Instructions::pop()
{
    GameState state = list.front();
    list.pop_front();
    return state;
}

bool Instructions::isEmpty() const
{
    return list.empty();
}

deque<GameState> Instructions::getList() const
{
    return list;
}

void Instructions::push(GameState state)
{
    list.push_back(state);
}

Instructions::Instructions()
{
    list = deque<GameState>();
}

Instructions::~Instructions()
{
}