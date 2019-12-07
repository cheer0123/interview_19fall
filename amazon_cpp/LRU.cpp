#include <iostream>
#include <unodered_map>


class ListNode {
    ListNode* next;
    ListNode* pre;
    int val;
    ListNode(int x):val(x), pre(NULL), next(NULL) {}
};

class Container() {
private:
    unordered_map<int, ListNode>  m;
    ListNode* head;
    ListNode* tail;
    int cap;
    int nodeCnt = 0;


public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next =tail;
        tail->pre = head;
    }
    
    void removeNode(ListNode* node) {
        ListNode* pre = node->pre;
        ListNode* next = node->next;

        pre->next = next;
        next->pre = pre;
        node->pre = NULL;
        node->next = NULL;
        nodeCnt--;
    }
    
    void insertToHead (ListNode* node) {
        ListNode* next = head->next;
        node->next = next;
        node->pre = head;
        head->next = node;
        nodeCnt++;
    }
    
    void moveTohead(ListNode* node) {
        removeNode(node);
        insertToHead(head);
    }
    
    void popTail () {
        ListNode* node = tail->pre;
        node->next = NULL;
        tail = node;
    }
    
    ListNode* get(int key) {
        if(m.count(key)) {
            ListNode node = m[key];
            moveTohead(node);
            return node->val;
        } 
        return -1;
    }
    
    void put(int val) {
        if(m.count(val)) moveTohead(node);
        else {
            node = new Node(val);
            m[val] = node;
            moveTohead(node);
           if(nodeCnt > capacity)
               popTail();
        }
    }
};

int mian() {
    
}

