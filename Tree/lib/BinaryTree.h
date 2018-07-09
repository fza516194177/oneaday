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

        // 别的骚操作
        BiNode * mirrorReverse(BiTree root);
        bool isMirrorBiTree(BiTree root);
        bool isMirrorBiTree_helper(BiTree root1, BiTree root2);
        bool isSameBiTree(BiTree root1, BiTree root2);
        bool isChildTree(BiTree father, BiTree son);
        bool isChildTree_helper(BiTree root1, BiTree root2);
        bool isBSTPostOrder(string str, int& start, int& to);
        void addNode(const ElemType key, int direction, BiTree root);
        BiTree m_root; // 根节点
        int size; // 节点总数
};
