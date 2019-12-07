// #include <iostream> 
// #include <vector> 
// //#include <bits/stdc++.h> 

// using namespace std; 
// class CategoryNode {
// public:
//     vector<CategoryNode*> children;
//     int val;
//     CategoryNode(int val) {
//     //   this->children = NULL;
//       this->val = val;
//     }
// };


// class Solution {
// public:
//   double max = -1000.0;
//   CategoryNode* res = NULL;
//   CategoryNode* getMostPopular(CategoryNode* root) {
//     if(root == NULL) return NULL;
//     helper(root);
//     return res;
//   }
  
//   vector<int> helper(CategoryNode* root) {
//     vector<int> tem;
//     int sum = root->val, size = 1;
//     for(auto child : root->children) {
//       tem = helper(child);
//       sum += tem[0];
//       size += tem[1];
//     }
//     double avg = (double) sum / size;
//     if (avg > max && size > 1) {
//         max = avg;
//       res = root;
//     }
//     vector<int> result;
//     result.push_back(sum);
//     result.push_back(size);
//     return result;
//   }
// };
#include <vector>
#include <iostream>

using namespace std;

class CategoryNode {
public:
    vector<CategoryNode*> children;
    int val;
    CategoryNode(int val) {
        this->val = val;
        
    }
};

class Solution{
private:
    CategoryNode* res = NULL;
    int max = -1000;
public:
    CategoryNode* mostPopular(CategoryNode* root) {
        if(root == NULL) 
            return NULL;
        helper(root);
        return res;
    }
    
public:
    vector<int> helper(CategoryNode* root) {
        //if(root == NULL) return {0, 0};
        
        int sum = 0, size = 1;
        vector<int> tem;
        for(auto child : root->children) {
            tem = helper(child);
            sum += tem[0];
            size += tem[1];
        }
        
        int avg = (double) sum / (double) size;
        if(avg > max) {
            max = avg;
            res = root;
        }
        vector<int> result;
        result.push_back(sum);
        result.push_back(size);
        return result;
    }
};

int main() {
    CategoryNode* node1 = new CategoryNode(1);
    CategoryNode* node2 = new CategoryNode(3);
    CategoryNode* node3 = new CategoryNode(4);
    CategoryNode* node4 = new CategoryNode(5);
    
    CategoryNode* node5 = new CategoryNode(2);
    CategoryNode* node6 = new CategoryNode(7);
    CategoryNode* node7 = new CategoryNode(15);
    
    CategoryNode* node8 = new CategoryNode(6);
    CategoryNode* node9 = new CategoryNode(12);
    CategoryNode* node10 = new CategoryNode(8);
    CategoryNode* node11 = new CategoryNode(11);
    vector<CategoryNode*> c1;
    c1.push_back(node2);
    c1.push_back(node3);
    c1.push_back(node4);
    
    vector<CategoryNode*> c2;
    c2.push_back(node5);
    c2.push_back(node6);
    
    vector<CategoryNode*> c3;
    c3.push_back(node7);
    
    vector<CategoryNode*> c4;
    c4.push_back(node8);
    c4.push_back(node9);
    c4.push_back(node10);
    
    vector<CategoryNode*> c5;
    c5.push_back(node11);
    
    node1->children = c1;
    node2->children = c2;
    node3->children = c3;
    node4->children = c4;
    node9->children = c5;
    Solution s;
    cout<<s.mostPopular(node1)->val<<"\n";
    return 0;
}
