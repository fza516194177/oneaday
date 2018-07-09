#include <iostream>
#include <vector>
#include "List.h"

using namespace std;

// create node by vector
Node * createList(vector<int> arr) {
    if (arr.empty()) {
        return NULL;
    }
    Node *head = new ListNode(0);
    Node *tmp = head;
    for (int i = 0; i < arr.size(); i++) {
        Node *n =  new Node(arr[i]);
        tmp->next = n;
        tmp = n;
    }
    
    cout << "create list done" << endl;
    return head;
}

// iterator
void printList(Node* head) {
    Node *tmp = head->next;
    while (tmp != NULL && tmp->next != NULL) {
        cout << tmp->data << " ->";
        tmp = tmp->next;
    }
    cout << tmp->data;
    cout << endl;
}

// O(1) delete node
void O1_delete(Node **head, Node *toDelete) {
    if(!head || !toDelete) {
        return;
    }
    // 删除的节点不是尾节点
    if (toDelete->next != NULL) {
        Node *p_next = toDelete->next;
        toDelete->data = p_next->data;
        toDelete->next = p_next->next;
        delete p_next;
        p_next = NULL;
    } else if (*head == toDelete) {
        // 只有一个节点
        delete toDelete;
        toDelete = NULL;
    } else {
        // 尾节点
        
        Node *tmp = *head;
        while (tmp && tmp->next != toDelete) {
            tmp = tmp->next;
        }
        if (tmp->next == toDelete) {
            tmp->next = NULL;
            delete toDelete;
            toDelete = NULL;
        }
    }
}

/*
Node* reverse(Node* n) {
    if (n == NULL || n->next == NULL) {
        return n;
    } else {
        // newHead是最后一个节点，归来时一直没有改变
        // 归来的时候，每个节点都保存在栈中，所以可以直接操作
        Node *newHead = reverse(n->next);
        n->next->next = n;
        n->next = NULL;
        return newHead;
    } 
}
*/

Node* reverse(Node* n) {
    Node *tail = NULL; 
    Node *pre = NULL;
    Node *now = NULL;
    Node *nex = NULL;
    now = n;
    while(now != NULL) {
        if (now->next == NULL) {
            tail = now;
        }
        nex = now->next;
        now->next = pre;
        
        pre = now;
        now = nex;
    }
    return tail;
}

// 链表倒数第K个节点
Node* KthNode(Node *head, int n) {
    if (n < 1 || head == NULL) {
        return NULL;
    }
    Node *fast = head;
    Node *slow = head;
    while(n>0 && fast != NULL) {
        fast = fast->next;
        n--;
    }
    if (n >0) {
        cout << "n超过链表长度" << endl;
        return NULL;
    }

    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
    return slow;
}

// 链表中间节点
Node * midNode(Node *head) {
    if (head == NULL)
        return NULL;

    Node *pre = head;
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL) {
        if (fast->next == NULL || fast->next->next == NULL) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
    return slow;
}

Node * merge(Node* head1, Node *head2) {
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    Node *root = new Node(0);
    Node *res = root;


    while (head1 && head2) {
        
        if (head1->data <= head2->data) {
            Node *tmp = new Node(head1->data);
            res->next = tmp;
            head1 = head1->next;
        } else {
            Node *tmp = new Node(head2->data);
            res->next = tmp;
            head2 = head2->next;
        }
        res = res->next;
    }
    if (head1) {
        res->next = head1;
    }
    if (head2) {
        res->next = head2;
    }

    return root->next;
}




int main() {
    int arr[] = {1,3,4,5,8};
    int arr2[] = {1,1,6,7};
    vector<int> ivec(arr,arr+5);
    vector<int> ivec2(arr2,arr2+4);
    Node *head = createList(ivec);
    Node *head2 = createList(ivec2);
    printList(head);
    printList(head2);
    Node *res = merge(head, head2);
    printList(res);
    //... O(1) delete
    //O1_delete(&head->next, head->next->next->next->next->next);
    //printList(head);
    //... reverse
    //Node *newHead = reverse(head);
    //printList(newHead);
    //... kthnode
    //Node *kthnode = KthNode(head,3);
    //... mid
    // Node *midnode = midNode(head);
    
    return 0;
}