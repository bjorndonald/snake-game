#include <deque>
using namespace std;
class Snake
{
private:
    int length;
    deque<int> body;
    int front;
    int back;
    int previous;

public:
    void pop();
    deque<int> getBody() const;
    void addLength();
    void push(short &position);
    bool isLocated(short &position);
    Snake();
    Snake(int &width, int &height);
    ~Snake();
};
