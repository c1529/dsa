#include <iostream>
using namespace std;

const int DEFAULT_CAPACITY = 10;

class SequentialList
{
private:
    int *data;
    int size;     // 当前大小
    int capacity; // 顺序表容量
public:
    SequentialList()
    { // 初始化
        data = new int[DEFAULT_CAPACITY];
        size = 0;
        capacity = DEFAULT_CAPACITY;
    }
    ~SequentialList()
    { // 析构函数，销毁
        delete[] data;
    }
    void insert(int element)
    {
        if (size < capacity)
        {
            data[size] = element;
            size++;
        }
        else
        {
            cout << "list is full" << endl;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << endl;
        }
    }
    void increase(int newcapacity)
    {
        int *newdata = new int[newcapacity]; // 创建临时新数组
        // 将顺序表的元素放到新数组里面
        for (int i = 0; i < size; i++)
        {
            newdata[i] = data[i];
        }
        // 删除原先顺序表的内存
        delete data;
        data = newdata;
        capacity = newcapacity;
    }
};
int main()
{
    SequentialList mylist;
    for (int i = 0; i < DEFAULT_CAPACITY + 2; i++)
    {
        mylist.insert(i);
    }
    mylist.display();
    return 0;
}
