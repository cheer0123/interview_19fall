#include <iostream> 
#include <vector> 

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) 
            return root->val == sum;
        return hasPathSum(root->left, sum-root->val) 
            || hasPathSum(root->right, sum-root->val);
            
    }
};


// find all root-to-leaf paths where each path's sum equals the given sum.
class Solution2 {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, sum, res, path);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<vector<int> > &res, vector<int> path) {
        if(root == NULL) return;
        sum -= root->val;
        path.push_back(root->val);
        if(root->left  == NULL && root->right == NULL) {
            if(sum == 0) res.push_back(path);
        }

        dfs(root->left, sum, res, path);
        dfs(root->right, sum, res, path);
        sum += root->val;
        path.pop_back();
    }
};