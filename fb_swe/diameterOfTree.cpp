#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct BSTTreeNode {
    int val;
    BSTTreeNode* left;
    BSTTreeNode* right;
    BSTTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode {
    int val;
    vector<TreeNode*> child;
    TreeNode(int _val, vector<TreeNode*> _child) {
        val = _val;
        child = _child;
    }
};


// We can do this task easily Using Recursion. 
// We will use the top down approach here i.e. 
// First we will go down to the leaf nodes and then collect the answer from the bottom.
// At each step, We will check for that node(Longest path passes through this node or not) 
// while we Move Up (return to the parent).


class Solution1{
    int res = 0;
public:
    int diameterOfBinaryTree(BSTTreeNode* root) {
        helper(root);
        return res;
    }
    
    int helper(BSTTreeNode* root) {
        if(root == NULL) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        res = max(l+r, res);
        return max(l, r) +1;
    }
};

class Solution3 {
private:
    int res = 0;
public:
    int diameterofTree(TreeNode* root) {
        if(root == NULL) return 0;
        helper(root);
        return res;
    }
    
    int helper(TreeNode* root) {
        if(root->child.size() == 0) return 1;
        int first = 0, second = 0;
        for(auto node:root->child) {
            int tem = helper(node);
            if(tem >= first) {
                second = first;
                first = tem;
            } else if(tem >= second) {
                second = tem;
            }
        }
        res = max(first + second, res);
        return first+1;
    }
};

// Ans = Height of left subtree + Height of the Right subtree + 1
// Key Point : Search for the node from where the Path goes down in both directions.



// we choose an arbitrary node (x) and find the farthest node from (x), let it be (y) ,
// then we do another traversal to find the farthest node from (y) , let it be (z).
// Then diameter is the distance between (y) and (z).

class Solution2 {
private:
    // <parent, child>
    unordered_map<TreeNode*, vector<TreeNode*> > g;
public:
    unordered_map<TreeNode*, TreeNode*> buildG(TreeNode* root) {
        for(auto c : root->child) {
            g[root].push_back(c);
            if(c) buildG(c);
        }
    }

    pair<int, TreeNode*> bfs(TreeNode* root){
        unordered_map<TreeNode*, int> dist;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            for(auto it : g[cur]){
                if(!dist.count(it)){
                    continue;
                }
                q.push(it);
                dist[it] = dist[cur] + 1;
            }
            q.pop();
        }
        int mx = INT_MIN;
        TreeNode* vertex;
        for(auto d:dist){
            if(mx < d.second){
                mx = d.second;
                vertex = d.first;
            }
        }
        return make_pair(mx, vertex);
    }

    int diameter(TreeNode* root){
        pair<int, TreeNode*> p1 = bfs(root);
        pair<int, TreeNode*> p2 = bfs(p1.second);
        return p2.first;
    }
};

int main () {
    vector<TreeNode*> child;
    TreeNode* root = new TreeNode(1, child);
    TreeNode* node2 = new TreeNode(2, child);
    TreeNode* node3 = new TreeNode(3, child);
    TreeNode* node4 = new TreeNode(4, child);
    TreeNode* node5 = new TreeNode(5, child);
    TreeNode* node6 = new TreeNode(6, child);
    TreeNode* node7 = new TreeNode(7, child);
    TreeNode* node8 = new TreeNode(8, child);
    TreeNode* node9 = new TreeNode(10, child);
    
    vector<TreeNode*> children2;
    vector<TreeNode*> children3;
    vector<TreeNode*> children4;
    vector<TreeNode*> children5;
    vector<TreeNode*> children6;
    vector<TreeNode*> children7;
    
    children2.push_back(node2);
    children3.push_back(node5);
    children3.push_back(node3);
    children4.push_back(node4);
    children5.push_back(node5);
    children6.push_back(node6);
    children7.push_back(node7);
    
    node3->child = children4;
    node2->child = children3;
    node6->child = children7;
    node5->child = children6;
    root->child = children2;
    

    Solution2 s;
    int res = s.diameter(root);
    cout<<res<<endl;
    return 0;
}

