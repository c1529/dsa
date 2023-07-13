#include <iostream>
using namespace std;
// typedef 让struct LNode跟LNode和*LinkList一样
// LNode *L和LinkList L的L都是表示指向单链表的第一个节点的指针
// 通常用LNode表示节点,LinkList表示链表
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
class LinkedList
{
private:
    LNode *head;

public:
    LinkedList()
    {
        // nullptr是表示空指针，相当于NULL，不过NULL有风险，就抛弃了
        head = new LNode;
        head->next = nullptr;
    }
    // 插入操作
    void ListInsert(int i, int e)
    {
        if (i < 0)
        {
            cout << "error" << endl;
            return;
        }
        // j表示p的位置，0表示头节点
        LNode *p = head;
        int j = 0;
        // 开始,在插入位置的前一个位置停下
        while (p != nullptr && j < i - 1)
        {
            p = p->next;
            j++;
        }
        // 如果p为空节点，则返回,前一个不为空节点
        if (p == nullptr)
        {
            return;
        }
        LNode *s = new LNode;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return;
    }
    // 指定节点前插入，节点后的太简单了
    void InsertPiorLNode(LNode *p, int e)
    {
        LNode *s = new LNode;
        s->next = p->next;
        p->next = s;
        s->data = p->data;
        p->data = e;
        return;
    }
    // 按照位序删除节点
    void ListDelete(int i)
    {
        if (i < 0)
        {
            cout << "error" << endl;
            return;
        }
        LNode *p = head;
        int j = 0;
        while (p != nullptr && j < i - 1)
        {
            p = p->next;
            j++;
        }
        if (p == nullptr)
        {
            return;
        }
        LNode *s = p->next;
        p->next = p->next->next;
        delete s;
        return;
    }
    // 按位查找
    void getelement(int i)
    {
        if (i < 0)
        {
            return;
        }
        LNode *p = head;
        int j = 0;
        while (p != nullptr && j < i)
        {
            p = p->next;
            j++;
        }
        if (p == nullptr)
        {
            return;
        }
        cout << p->data << endl;
    }
    // 显示链表
    void display()
    {
        LNode *p = head->next;
        while (p != nullptr)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
};
int main()
{
    LinkedList mylist;
    mylist.ListInsert(1, 2);
    mylist.ListInsert(1, 3);
    mylist.ListInsert(3, 8);
    mylist.ListInsert(4, 5);
    mylist.display();
    // 使用前先把head变成public
    // cout<<endl;
    // LNode *s = mylist.head->next->next;
    // cout<<s->data<<endl;
    // cout<<endl;
    // mylist.InsertPiorLNode(s,9);
    // mylist.display();
    mylist.ListDelete(2);
    mylist.display();
    mylist.getelement(2);
    return 0;
}
