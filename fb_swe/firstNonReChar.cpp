// Given a stream of characters, find the first non-repeating character from stream. 
// You need to tell the first non-repeating character in O(1) time at any moment.


// The idea is to use a DLL (Doubly Linked List) to efficiently get the first 
// non-repeating character from a stream. 
// The DLL contains all non-repeating characters in order, 
// i.e., the head of DLL contains first non-repeating character, the second node contains the second non-repeating and so on.
// We also maintain two arrays: one array is to maintain characters that are already visited two or more times, we call it repeated[],
//  the other array is array of pointers to linked list nodes, we call it inDLL[]

#include <iostream> 
#include <vector> 
#define MAX_CHAR 256
using namespace std;

struct Node {
    char a;
    Node *next, *prev;
    Node(char x): a(x), next(NULL), prev(NULL) {}
};

class Solution {
private:
    Node* head = NULL;
    Node* tail = NULL;

public:
    void appendNode (char x) {
        Node* tem = new Node(x);
        if(head == NULL) {
            head = tem;
            tail = tem;
            return;
        }
        tail->next = tem;
        tem->prev = tail;
        tail = tem;
    }

    // Note that the function may change head and tail pointers, 
    // that is why pointers to these pointers are passed. 
    void removeNode(Node* tem) {
        if(head == NULL) return;
        if(head == tem) head = (head)->next;
        if(tail == tem) tail = (tail)->prev;
        if(tem->next != NULL) tem->next->prev = tem->prev;
        if(tem->prev != NULL) tem->prev->next = tem->next;
        delete(tem);
    }

    // A utility function to append a character x at the end of DLL.
    // Note that the function may change head and tail 
    // pointers, that is why pointers to these pointers are passed. 

    char findFirstNonRepeat(string stream) {
        vector<Node*> DLL(MAX_CHAR, NULL);
        vector<bool> repeated(MAX_CHAR, false);
        for(int i=0; i<stream.size(); i++) {
            char c = stream[i];
            // We process this character only if it has not occurred 
            // or occurred only once. repeated[x] is true if x is 
            // repeated twice or more.s 
            if(!repeated[c]) {
                // If the character is not in DLL, then add this at 
                // the end of DLL. 
                if(DLL[c] == NULL) {
                // If the character is not in DLL, didn't appear before  
                // then add this at the end of DLL.  
                    appendNode(c);
                    DLL[c] = tail;
                } else {
                    // Otherwise(appeared before) remove this character from DLL 
                    removeNode(DLL[c]);
                    DLL[c] = NULL;
                    repeated[c] = true;
                }
            }
        }
        char res;
        if(head != NULL) res = head->a;
        return res;
    }
};

int main() {
    Solution s;
    char c  = s.findFirstNonRepeat("1233451233");
    cout<<"1st non repeating char is:  "<< c <<endl;
    return 0;
}