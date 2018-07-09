#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    string key;
    string data;
    Node *prev, *next;
};

class Cache {
    private:
        // 删除节点
        void detach(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        // 头插节点
        void attach(Node *node) {
            node->prev = head_; 
            node->next = head_->next;
            head_->next->prev = node;
            head_->next = node;
        }

    private:
        unordered_map<string, Node*> hashmap_;
        // 存储可用节点
        vector<Node*> free_entries_;
        Node *head_, *tail_;
        Node *entries_;

    public:
        Cache(size_t size) {
            entries_ = new Node[size];
            for (int i = 0; i < size; i++) {
                free_entries_.push_back(entries_+i);
            }
            head_ = new Node;
            tail_ = new Node;
            head_->prev = NULL;
            head_->next = tail_;
            tail_->prev = head_;
            tail_->next = NULL;
        }

        ~Cache() {
            delete head_;
            delete tail_;
            delete [] entries_;
        }

        void Put(string key, string data) {
            // 先看map中有没有,有则更新放list头
            // 无则获取一个新的节点放list头
            Node *n = hashmap_[key];
            if (n) {
                // update
                detach(n);
                n->data = data;
                attach(n);
                printf("put - move %s to first\n", n->data.c_str());
            } else {
                // 从free数组中获取一个空节点
                if (!free_entries_.empty()) {
                    n = free_entries_.back();
                    free_entries_.pop_back();
                } else {
                    n = tail_->prev;
                    detach(n);
                    hashmap_.erase(n->key);
                    printf("put - delete %s to set new val\n", n->data.c_str());
                }
                n->key = key;
                n->data = data;
                hashmap_[key] = n;
                attach(n);
            }
        }

        string Get(string key) {
            Node *n = hashmap_[key];
            if (n) {
                detach(n);
                attach(n);
                printf("get - move %s to first\n", n->data.c_str());
                return n->data;
            } else {
                return "";
            }
        }

        void PrintList() {
            Node *tmp = head_->next;
            cout << " ====> " ;
            while (tmp && tmp != tail_) {
                cout << tmp->data << " ->";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

int main() {
    Cache c(3);
    c.Put("a","first");
    c.Put("b","second");
    c.Put("c","third");
    c.PrintList();
    c.Put("d","fourth");
    c.PrintList();
    return 0;
}
