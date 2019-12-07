#include <iostream> 
#include <vector> 
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void heapifyhelper(vector<int> &A, int n, int i) {
        int l = 2*i+1, r = 2*i+2;
        int largest = i;
        if(l<n && A[l] > A[largest]) {
            largest = l;
        }
        if(r<n && A[r] > A[largest]) {
            largest = r;
        }
        if(largest != i) {
            swap(A[largest], A[i]);
            heapifyhelper(A, n, largest);
        }
    }

    void heapify(vector<int> &A, int n) {
        for (int i=n/2; i>=0; i--) {
            heapifyhelper(A, n, i);
        }
    }

    TreeNode* buildTree(vector<int> &A) {
        int n = A.size();
        heapify(A, n);
        return buildhelper(A, 0);
    }

    TreeNode* buildhelper(vector<int> &A, int  i) {
        if(i >= A.size()) return NULL;
        TreeNode* root = new TreeNode(A[i]);
        root->left = buildhelper(A, 2*i+1);
        root->right = buildhelper(A, 2*i+2);
        return root;
    }

    void printTree(TreeNode* root) {
        if(root == NULL) return;
        cout<<root->val<<endl;
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    vector<int> A;
    A.push_back(7);
    A.push_back(8);
    A.push_back(9);
    A.push_back(4);
    A.push_back(10);
    A.push_back(5);
     Solution s;
     TreeNode* node = s.buildTree(A);
     s.printTree(node);
     return 0;
}