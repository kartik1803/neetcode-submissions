/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    pair<int,int>solve(TreeNode*root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        int h1=left.first;
        int h2=right.first;
        int d1=left.second;
        int d2=right.second;
        int h =max(h1,h2)+1;
        int d=max(d1,max(d2,h1+h2));
        return {h,d};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second;
    }
};
