#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef char ElemType;

typedef struct   BiNode
{
    ElemType data;
    BiNode * left;
    BiNode * right;
    BiNode(ElemType elem) 
    {
        data = elem;     
        left = NULL;
        right = NULL;
    }
} BiNode, *BiTree;

class BinaryTree
{
    public:
        BiNode* createNode();
        BiTree create(const string& str, int& index);
        void preOrder(BiTree root);
        void preOrderIter(BiTree root);
        void inOrderIter(BiTree root);
        void inOrder(BiTree root);
        void postOrder(BiTree root);
        void postOrderIter(BiTree root);
        void transLevelEasy(BiTree root); 
        void transLevel(BiTree root);
        void destroy(BiTree root);
        int getHeight(BiTree root);
        void addNode(const ElemType key, int direction, BiTree root);
        BiTree m_root; // 根节点
        int size; // 节点总数
};
