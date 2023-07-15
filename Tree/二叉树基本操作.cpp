#include <iostream>
using namespace std;
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
class Tree
{
private:
    BiTNode *root;

public:
    Tree()
    {
        root = nullptr;
    }
    // 在二叉树中插入节点
    void insert(int value)
    {
        insertNode(root, value);
    }

private:
    void insertNode(BiTNode *&node, int value)
    {
        if (node == nullptr)
        {
            node = new BiTNode;
            node->data = value;
            node->lchild = nullptr;
            node->rchild = nullptr;
        }
        else if (value < node->data)
        {
            insertNode(node->lchild, value);
        }
        else
        {
            insertNode(node->rchild, value);
        }
    }

public:
    void display()
    {
        displayTree(root);
    }

private:
    void displayTree(BiTNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        displayTree(node->lchild);
        // cout << node->data << endl;
        displayTree(node->rchild);
        cout << node->data << endl;
    }
};
int main()
{
    Tree mytree;
    mytree.insert(1);
    mytree.insert(2);
    mytree.insert(3);
    mytree.insert(4);
    mytree.insert(5);
    mytree.display();
    return 0;
}
