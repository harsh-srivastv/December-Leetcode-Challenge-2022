// https://leetcode.com/problems/leaf-similar-trees/description/

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void travel(TreeNode* root, vector<int>& arr){
        if(root->left==NULL and root->right==NULL){
            arr.push_back(root->val);
        }
        if(root->left != NULL){
            travel(root->left, arr);
        }
        
        if(root->right != NULL){
            travel(root->right, arr);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;

        travel(root1, res1);
        travel(root2, res2);

        if(res1.size() != res2.size()){
            return false;
        }
        else{
            for(int i=0;i<res1.size();i++){
                if(res1[i] != res2[i]){
                    return false;
                }
            }
        }
        return true;
    }
};