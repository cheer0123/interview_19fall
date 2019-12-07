#include <iostream> 
#include <vector> 

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new  ListNode(-1);
        ListNode* cur = dummy;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return dummy->next;
    }

    // ListNode* mergeWithoutDulplicate(ListNode* l1, ListNode* l2) {
    //     ListNode* dummy = new ListNode(-1);
    //     ListNode* cur = dummy;
    //     while(l1 && l2) {
    //         if (cur == dummy) {
    //             if (l1->val <= l2->val) {
    //                 cur->next = l1;
    //                 l1 = l1->next;
    //                 cur = cur->next;
    //             } else {
    //                 cur->next = l2;
    //                 l2 = l2->next;
    //                 cur = cur->next;
    //             }
    //         } else {
    //             while(l1 && l1->val == cur->val) l1 = l1->next;
    //             while(l2 && l2->val == cur->val) l2 = l2->next;
    //             if(!l1 || !l2) break;
    //             if(l1->val < l2->val) {
    //                 cur->next = l1;
    //                 l1 = l1->next;
    //             } else {
    //                 cur->next = l2;
    //                 l2 = l2->next;
    //             } 
    //             cur = cur->next;
    //         }
    //     }
    //     return dummy->next;
    // }
};


int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node11 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node22 = new ListNode(2);
    
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);
    node1->next = node11;
    node11->next = node2;
    node2->next = node6;
    node6->next = node7;
    
    node2->next = node22;
    node22->next = node8;
    // while(node1) {
    //     cout<<node1->val<<endl;
    //     node1=node1->next;
    // }
    // cout<<"____"<<endl;
    // while(node2) {
    //     cout<<node2->val<<endl;
    //     node2=node2->next;
    // }
    Solution s;
    // ListNode* res1 = s.mergeWithoutDulplicate(node1, node2);
    // while(res1) {
    //     cout<<res1->val<<endl;
    //     res1 =  res1->next;
    // }

    ListNode* res2 = s.mergeTwoLists(node1, node2);
    while(res2) {
        cout<<res2->val<<endl;
        res2 =  res2->next;
    }

    return 0;
}