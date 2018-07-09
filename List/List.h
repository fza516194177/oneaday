#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct ListNode {
    ElemType data;    
    ListNode *next, *prev;
    ListNode(ElemType d) {
        data = d; 
        next = NULL;
        prev = NULL;
    }
} Node;

