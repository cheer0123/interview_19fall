#include <iostream> 
#include <vector> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        if (!backtrack(root, p, path1) || !backtrack(root, q, path2)) 
            return -1;
        int i=0;
        for (; i<path1.size() && i<path2.size(); i++) {
            if (path1[i]->val != path2[i]->val) {
                 break;
            }
        }
        return path1.size() - i + path2.size() - i -1;
    }
    
    bool backtrack(TreeNode* root, TreeNode* p, vector<TreeNode*> &path) {
        if (root == NULL)
            return false;
        path.push_back(root);
        if (root->val == p->val)
            return true;
        if ( (root->left && backtrack(root->left, p, path))
            || (root->right && backtrack(root->right, p, path)) )
            return true;
        path.pop_back();
        return false;
    }
};


int main () {
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(0);
    TreeNode* node6 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(4);
    TreeNode* node9 = new TreeNode(10);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node4->left = node7;
    node4->right = node8;
    Solution s;
    int res = s.lowestCommonAncestor(root, node1, node9);
    cout<<res<<endl;
    return 0;
}

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        return l? l:r;
    }
};

