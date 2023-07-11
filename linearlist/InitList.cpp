#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

class LinearList
{
private:
    int data[MAX_SIZE];
    int size;

public:
    LinearList()
    {
        size = 0; // 初始化线性表
    }
    // 插入元素
    void insert(int element)
    {
        if (size < MAX_SIZE)
        {
            data[size] = element;
            size++;
        }
        else
        {
            cout << "The linear table is full and no new elements can be inserted." << endl;
        }
    }
    // 显示线性表
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << endl;
        }
    }
};
int main()
{
    LinearList mylist;
    for(int i=2;i<5;i++){
        mylist.insert(2*i+1);
    }
    mylist.display();
    return 0;
}
