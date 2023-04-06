#include <deque>
#include "GameState.hpp"
using namespace std;

class Instructions
{
private:
    int length;
    deque<GameState> list;
    int front;
    int back;

public:
    GameState pop();
    bool isEmpty() const;
    deque<GameState> getList() const;
    void push(GameState state);
    Instructions();
    ~Instructions();
};
