// 栈是后进先出
// 顺序栈用静态数组就可以
#include <iostream>
using namespace std;
// 链式栈
typedef struct Linknode
{
    int data;
    struct Linknode *next;
} *Listack;
class Stack
{
private:
    Listack top;

public:
    Stack()
    {
        top = nullptr;
    }
    // 入栈
    void push(int e)
    {
        Linknode *p = new Linknode;
        p->data = e;
        if (top == nullptr)
        {
            top = p;
        }
        else
        {
            p->next = top;
            top = p;
        }
    }
    // 出栈
    void pop()
    {
        if (top == nullptr)
        {
            cout << "error" << endl;
        }
        Linknode *p = top;
        top = top->next;
        delete p;
    }

    void display()
    {
        Linknode *p = top;
        cout << p->data << endl;
    }
};
int main()
{
    Stack stack;
    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
    }
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}
