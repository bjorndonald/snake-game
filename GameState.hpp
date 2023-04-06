class GameState
{
private:
    const int direction;
    const int step;

public:
    int getStep() const;
    int getDirection() const;
    GameState();
    GameState(const int &direction, int &step);
    ~GameState();
};
