#include "Snake.hpp"
// #include "GameHistory.hpp"

class Game
{
private:
    int *cells;
    bool gameOver = false;
    int width;
    int height;
    int step;
    int fruitCount = 0;
    int fruitPosition;
    // GameHistory history;
    Snake snake;
    int direction;
    const static int DEFAULT_WIDTH = 20;
    const static int DEFAULT_HEIGHT = 20;

public:
    Game();
    Game(int &width, int &height);
    ~Game();
    int getStep() const;
    void draw();
    void input(int c);
    void input();
    void setup();
    void snakeMove();

    int *getCells();
};
