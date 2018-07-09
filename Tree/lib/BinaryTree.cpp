#include "BinaryTree.h"
#include <string>
#include <queue>

/* 
 * key: 要插入的值
 * way: 左边 0 右边 1
 * root: 根节点
 */
/*
void BinaryTree::addNode(const ElemType key, int way, BiTree root) {
    // 左边插入
    if (way == 0) {
        if (root->left == NULL) {
            root->left = new BiNode(key);
        } else {
            addNode(key, way, root->left);
        }
    } else if(way == 1) {
        if (root->right == NULL) {
            root->right = new BiNode(key);
        } else {
            addNode(key, way, root->right);
        }
    }
}
*/

BiNode* BinaryTree::createNode() {
    BiNode *ret = (BiNode*)malloc(sizeof(BiNode));
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}


// 按照前序遍历方式建立二叉树
//  preOrder : "abc##de#g##f### "
//  index : 0
BiTree BinaryTree::create(const string &preOrder , int& index)
{
    if ( index >= preOrder.size() )  {
        return NULL;
    }
    if (preOrder[index] == '#') {
        index++;
        return NULL;
    }
    BiNode* p = new BiNode(preOrder[index++]);
    p->left = create(preOrder, index);
    p->right = create(preOrder, index);
    return p;
}


// 中序遍历
void BinaryTree::inOrder(BiTree root) 
{
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data  << " ";
        inOrder(root->right);
    }
    return;
}

// 中序非递归
void BinaryTree::inOrderIter(BiTree root) 
{
    stack<BiNode *> s; 
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            cout << root->data << " "; // 访问完左子树才访问根节点
            s.pop();
            root = root->right; // 访问右子树
        }
    }
}

// 前序遍历
void BinaryTree::preOrder(BiTree root) 
{
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}

// 前序遍历非递归
void BinaryTree::preOrderIter(BiTree root)
{
    if (root == NULL) 
        return;
    stack <BiNode *> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            cout << root->data << " ";
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

// 后序遍历
void BinaryTree::postOrder(BiTree root) {
    if (root !=NULL ) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    return;
}

// 后序遍历（非递归）
/*
void BinaryTree::postOrderIter(BiTree root) 
{
    if (root == NULL) 
        return;
    stack<BiNode *> s;
    stack<ElemType> res;
    s.push(root);
    while (!s.empty()) {
        root = s.top();
        s.pop();
        res.push(root->data);
        if (root->left != NULL)
            s.push(root->left);
        if (root->right != NULL)
            s.push(root->right);
    }

    // 打印队列
    
    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    
    return;
}
*/
void BinaryTree::postOrderIter(BiTree root) 
{
    if (root == NULL) 
        return;
    stack<BiNode *> s;
    BiNode *pre = NULL; 
    BiNode *cur = NULL; 
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        if ((cur->left == NULL && cur->right == NULL) || ((pre != NULL) && (pre == cur->left || pre == cur->right))) {
            cout << cur->data << " ";
            s.pop();
            pre = cur;
        } else {
            if (cur->right) {
                s.push(cur->right);
            }
            if (cur->left) {
                s.push(cur->left);
            }
        }
    } 

    
    return;
}
// 获取树高
int BinaryTree::getHeight(BiTree root) {
    if (root == NULL) {
        return 0;
    }
    int lh =  getHeight(root->left) + 1;
    int rh =  getHeight(root->right) + 1;
    return max(lh, rh);
}

// 层次遍历 （不分层）
void BinaryTree::transLevelEasy(BiTree root) 
{
    if (root == NULL) {
        return;
    }
    queue<BiNode *> q;
    q.push(root);
    while(!q.empty()) {
        root = q.front();
        cout << root->data << " ";
        q.pop();
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
}


//  层次遍历(分层)
/*
void BinaryTree::transLevel(BiTree root)
{
    if (root == NULL) 
        return;
    queue<BiNode *> q1,q2;
    //queue<BiNode *> q2;

    q1.push(root);
    while (!q1.empty() || !q2.empty()) {
        // 打印q1中的节点
        if (!q1.empty()) {
            root = q1.front();
            q1.pop();
            cout << root->data << " ";
            if (root->left)
                q2.push(root->left);
            if (root->right)
                q2.push(root->right);
        } else {
            cout << ", " << endl;
            swap(q1,q2);
        }
      
        
    }
}
*/

//  层次遍历(之)
void BinaryTree::transLevel(BiTree root)
{
    if (root == NULL) 
        return;
    stack<BiNode *> s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            root = s1.top();
            cout << root -> data << " ";
            s1.pop();
            if (root->left) {
                s2.push(root->left);
            }
            if (root->right) {
                s2.push(root->right);
            }
        }
        cout << endl;
        while (!s2.empty()) {
            root = s2.top();
            cout << root->data << " ";
            s2.pop();
            if (root->right) {
                s1.push(root->right);
            }
            if (root->left) {
                s1.push(root->left);
            }
        }
        cout  << endl;
    }
}

//  镜像翻转
BiNode * BinaryTree::mirrorReverse(BiTree root) 
{
    if (root == NULL)
        return root;
    BiNode *temp = mirrorReverse(root->left);
    root->left = mirrorReverse(root->right);
    root->right  = temp;
    return root;
}

// 判断是不是镜像二叉树
bool BinaryTree::isMirrorBiTree(BiTree root) 
{
    if (root == NULL)
        return false;
    return isMirrorBiTree_helper(root, root);

}
bool BinaryTree::isMirrorBiTree_helper(BiTree root1, BiTree root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL) 
        return false;
    // 还有真实值的比较啊！！
    if (root1->data != root2->data) {
        return false;
    }
    return  isMirrorBiTree_helper(root1->left, root2->right) 
            && isMirrorBiTree_helper(root1->right, root2->left);
}

// 判断两个二叉树是不是相同
bool isSameBiTree(BiTree root1, BiTree root2)
{
    if (root1 == NULL && root2 == NULL) 
        return true;
    if (root1 == NULL || root2 == NULL) 
        return false;   
    if (root1->data != root2->data) 
        return false;
    return isSameBiTree(root1->left, root2->left) && isSameBiTree(root1->right, root2->right);
}

// 判断一个树是不是另一个树的子树
/*
bool isChildTree(BiTree father, BiTree son)
{
    if (father == NULL && son == NULL)
        return true;
    if (father == NULL)
        return false;
    bool flag = false;
    if (father != NULL && son != NULL) {
        // 如果值相等，说明是交点了， 找别的值
        if (father->data == son->data) {
            flag = isChildTree_helper(father , son);
        }
        if (!flag) {
            flag = isChildTree(father->left, son);
        }
        if (!flag) {
            flag = isChildTree(father->right, son);
        }
    }
    return flag;
}

bool isChildTree_helper(BiTree root1, BiTree root2)
{
    // 这里注意区分父子关系
    if (root1 == NULL)
        return false;
    if (root2 == NULL) 
        return true;
    if (root1->data != root2->data)
        return false;
    return isChildTree_helper(root1->left, root2->left) &&
           isChildTree_helper(root1->right, root2->right);
        
}
*/

// 判断一个序列是不是二叉搜索树的后序遍历
bool isBSTPostOrder(string str, int& start, int& to)
{
    
}


////////////
///// test
////////////
int main() {
    // 创建二叉树
    BinaryTree * bt = new(BinaryTree);
    string str = "abc##de#g##f###";
    int index = 0;
    BiTree tree = bt->create(str, index);
    // 中序遍历
    cout << "===>中序:" << endl;
    bt->inOrder(tree);
    cout << endl;
    // 中序遍历(非递归)
    cout << "===>中序:(非递归)" << endl;
    bt->inOrderIter(tree);
    cout << endl;
    // 前序遍历
    cout << "===>前序:" << endl;
    bt->preOrder(tree);
    cout << endl;
    // 前序遍历（非递归）
    cout << "===>前序:(非递归)" << endl;
    bt->preOrderIter(tree);
    cout << endl;
    // 后序遍历
    cout << "===>后序:" << endl;
    bt->postOrder(tree);
    cout << endl;
    // 后序遍历（非递归）
    cout << "===>后序:(非递归)" << endl;
    bt->postOrderIter(tree);
    cout << endl;
    // 获取树高
    cout << "===>获取Tree Height为：" << endl;
    int height = bt->getHeight(tree);
    cout << height << endl;
    // 层次遍历不分层（BFS，使用队列）
    cout << "===>层次遍历：" << endl;
    bt->transLevelEasy(tree);
    cout << endl;
    // 层次遍历不分层（BFS，使用队列）
    cout << "===>层次遍历(分层)：" << endl;
    bt->transLevel(tree);
    cout << endl;
    return 0;
}
