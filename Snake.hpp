#include <deque>
using namespace std;
class Snake
{
private:
    int length;
    deque<int> body;
    int front;
    int back;

public:
    void pop();
    deque<int> getBody() const;
    void push(int &position);
    bool isLocated(short &position);
    Snake();
    Snake(int &width, int &height);
    ~Snake();
};
