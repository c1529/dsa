#include <iostream>
using namespace std;
const int MAX_SIZE = 10; // 定义最大容量

class SeqList
{
private:
    int data[MAX_SIZE];
    int length; // 当前长度
public:
    SeqList()
    {
        length = 0;
    }
    void InsertList(int element)
    {
        if (length == MAX_SIZE)
        {
            cout << "Sequence table is full" << endl;
        }
        data[length] = element;
        length++;
    }
    void ListInsert(int i, int e)
    {
        if (i < 0 || i > length)
        {
            cout << "Invalid insertion postion" << endl;
            return;
        }
        if (length == MAX_SIZE)
        {
            cout << "Sequence table is full and cannot be inserted" << endl;
            return;
        }
        for (int j = length; j >= i; j--)
        {
            data[j] = data[j - 1];
        }
        data[i - 1] = e;
        length++;
    }
    // 顺序表的删除，删除第i个位置的元素，返回删除元素的值
    void ListDelete(int i, int &e)
    {
        // 判断i的位置是否合法
        if (i < 1 || i > length)
        {
            cout << "your number you gave don't add up" << endl;
            return;
        }
        e = data[i - 1];
        for (int j = i; j < length; j++)
        {
            data[j - 1] = data[j];
        }
        length--;
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << endl;
        }
    }
    // 顺序表查找--按位查找
    void getelement(int i, int &e)
    {
        if (i < 1 || i > length)
        {
            cout << "your number you gave is error" << endl;
            return;
        }
        e = data[i - 1];
    }
    // 按值查找
    int locationelement(int e){
        for(int i=0;i<length;i++){
            if(data[i]==e){
                return i+1;
            }
        }
        return -1;
    }
};
int main()
{
    SeqList mylist;
    mylist.InsertList(1);
    mylist.InsertList(5);
    mylist.InsertList(6);
    mylist.InsertList(62);
    mylist.InsertList(56);
    mylist.InsertList(66);
    mylist.display();
    cout << endl;
    mylist.ListInsert(4, 3);
    mylist.display();
    int e = 0;
    mylist.ListDelete(2, e);
    cout << "your number you deleted is " << e << endl;
    mylist.display();
    cout<<endl;
    int get = 0;
    mylist.getelement(2,get);
    cout<<get<<endl;
    cout<<mylist.locationelement(56)<<endl;
    return 0;
}
