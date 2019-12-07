#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int key, int val) : next(NULL), pre(NULL) {}
};

class LRUCache {
private:
        unordered_map<int, Node*> m;
        Node* head;
        Node* tail;
        int cap;
        int cnt;
public:
    LRUCache(int capacity) {
        capacity = cap;
        cnt = 0;
        head = NULL;
        tail = NULL;
    }
    
    void removeNode(Node* node) {
        Node* pre = node->pre;
        Node* next = node->next;
        pre->next = next;
        next->pre = pre;
    }
    
    // Always add the new node right after head;
    void addToHead(Node* node) {
        node->pre = head;
        node->next = head;

        head->next->pre = node;
        head->next = node;
    }
    
    void popTail() {
        Node* res = tail->pre;
        removeNode(tail);
        tail = res;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        Node* node = m[key];
        addToHead(node);
        removeNode(node);
        return m[key]->val;
    }
    
    void put(int key, int val) {
        if(m.count(key)) {
            Node* node = m[key];
            node->val = val;
            addToHead(node);
            removeNode(node);
        }
        else {
            Node* node = new Node(key, val);
            m[key] = node;
            cnt++;
            if(cnt > cap) {
                popTail();
                cnt--;
            }
            addToHead(node);
        }
    }
};

int main() {
    LRUCache lru(10);
    lru.put(1, 1);
    lru.put(2, 2);
    cout<< lru.get(1) <<endl;;
    lru.put(3, 3);
    cout<<lru.get(2)<<endl;
    lru.put(4, 4);
    cout<<lru.get(1)<<endl;;
    cout<<lru.get(3)<<endl;
    cout<<lru.get(4)<<endl;
    return 0;
}

