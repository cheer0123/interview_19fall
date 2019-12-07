#include <unordered_map>
#include <iostream>

using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(NULL), right(NULL){}
};


class Solution {
    unordered_map<Node*, Node*> m;
public:
    Node* cloneLR(Node* root, int upper, int lower) {
        if(root == NULL) return NULL;
        if(root->val > upper && root->val < lower) return NULL;
        Node* newNode = new Node(root->val);
        root->left = cloneLR(root->left, upper, lower);
        root->right = cloneLR(root->right, upper, lower);
        return newNode;
    }
    
    void printInorder(Node* root) {
        if(root == NULL) return;
        printInorder(root->left);
        cout<<root->val<<endl;
        printInorder(root->right);
    }
};

int main() {
    Solution s;
    Node* root = new Node(6); 
    root->left = new Node(2);
    root->right = new Node(5);
    Node* clone = s.cloneLR(root, 4, 0);
    s.printInorder(clone);
    return 1;
}




// duplicate a BST, but only include numbers in a given range