#include "Snake.hpp"
class Game
{
private:
    int *cells;
    bool gameOver = false;
    int width;
    int height;
    Snake snake;
    int direction;
    const static int DEFAULT_WIDTH = 20;
    const static int DEFAULT_HEIGHT = 20;

    /* data */
public:
    Game();
    Game(int &width, int &height);
    ~Game();
    void draw();
    void input(int c);
    void input();
    void setup();
    void snakeMove(const int &direction);

    int *getCells();
};
