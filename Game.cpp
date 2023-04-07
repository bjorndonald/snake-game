#include "Game.hpp"
// #include "Instructions.hpp"
// #include "History.hpp"
// #include "GameState.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <future>
#include <thread>
#include <chrono>
#include <termios.h>
#include <termios.h>
#define key 1

using namespace std;
// Fail system
char getch()
{
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return (buf);
}

void Clear()
{
#if defined _WIN32
    system("cls");
    // clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

int *Game::getCells()
{
    return nullptr;
}

Game::Game()
{
    direction = DOWN;
    cells = new int[DEFAULT_WIDTH * DEFAULT_WIDTH];
    width = DEFAULT_WIDTH;
    height = DEFAULT_HEIGHT;
    snake = Snake(width, height);
    step = 0;
    // history = History();
}

Game::Game(int &width, int &height)
{
    direction = DOWN;
    this->width = width;
    this->height = height;
    cells = new int[width * height];
    snake = Snake(width, height);
    step = 0;
    // history = History();
}

Game::~Game()
{
    delete[] cells;
}

int Game::getStep() const
{
    return step;
}

char getInput()
{

    char input;

    thread t1([&]()
              { input = getch(); });
    this_thread::sleep_for(chrono::milliseconds(10));
    t1.detach();

    return input;
}

void Game::input()
{
    char input = getInput();

    switch (input)
    {
    case 'a':
        if (direction != RIGHT)
        {
            direction = LEFT;
        }

        break;
    case 'd':
        if (direction != LEFT)
            direction = RIGHT;

        break;
    case 'w':
        if (direction != DOWN)
            direction = UP;

        break;
    case 's':
        if (direction != UP)
            direction = DOWN;

        break;
    case 'x':
        gameOver = true;
        break;
    default:
        break;
    }

    if (input == 'a' || input == 'w' || input == 's' || input == 'd')
    {
        // GameState state = GameState(direction, step);
        // history.push(state);
    }
}

static std::string getAnswer()
{
    std::string answer;
    std::cin >> answer;
    return answer;
}

void Game::setup()
{

    while (true)
    {
        if ((step % (width - fruitCount)) == 0)
        {
            short range = width * height + 1;
            fruitPosition = rand() % range;
        }

        input();
        Clear();
        draw();
        snakeMove();
        if (gameOver)
            break;
        usleep(1000000);
        step++;
    }
    cout << endl
         << "Game Over" << endl;
}

void Game::snakeMove()
{
    snake.pop();
    int end = snake.getBody().back();
    int j = end % height;
    int i = (end / width);
    short index;

    if (direction == LEFT)
    {

        index = (i * width) + --j;
    }
    if (direction == RIGHT)
    {
        index = (i * width) + ++j;
    }
    if (direction == UP)
    {
        index = (--i * width) + j;
    }
    if (direction == DOWN)
    {
        index = (++i * width) + j;
    }
    if ((i == 0 || i == width || j == 0 || j == height))
    {
        gameOver = true;
        return;
    }
    if (index == fruitPosition)
    {
        fruitCount++;
        short range = width * height + 1;
        fruitPosition = rand() % range;
        snake.addLength();
    }

    snake.push(index);
}

void Game::draw()
{
    for (short index = 0; index < width * height; index++)
    {
        int i = index % height;
        int j = (index / width);
        if (snake.isLocated(index))
        {
            cout << setw(2) << "O";
            continue;
        }
        if (index == fruitPosition)
        {
            cout << setw(2) << "Q";
            continue;
        }
        if (!snake.isLocated(index) && j != height - 1 && j != 0)
        {
            cout << setw(2) << " ";
            continue;
        }

        if (i == width - 1)
        {
            cout << "~]" << endl;
            continue;
        }
        if (i == 0)
        {
            cout << "[~";
            continue;
        }

        if (j == height - 1)
        {
            cout << setw(2) << '-';
            continue;
        }
        if (j == 0)
        {
            cout << setw(2) << "-";
            continue;
        }

        if (i == width - 1 && j == height - 1)
        {
            cout << endl;
        }
    }

    cout << "Press W, A, S, D for UP, LEFT, DOWN, RIGHT" << endl;
    cout << "Score: " << fruitCount * 2 << endl;
}
