#include "Snake.hpp"
#include <deque>
using namespace std;
void Snake::pop()
{
    body.pop_front();
}
deque<int> Snake::getBody() const
{
    return body;
}
void Snake::push(int &position)
{
    body.push_back(position);
}
bool Snake::isLocated(short &position)
{
    for (short n : body)
    {
        if (n == position)
            return true;
    }
    return false;
}
Snake::Snake()
{
}
Snake::Snake(int &width, int &height)
{
    body = deque<int>();
    int verticalMiddle = width / 2;
    int i = 1;
    int j = verticalMiddle - 1;
    while (i < 6)
    {
        int index = (i * width) + j;
        body.push_back(index);
        i++;
    }
    front = body.front();
    back = body.back();
}

Snake::~Snake()
{
}