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
    pair<int,bool>solve(TreeNode*root){
        if(root==NULL){
            return {-1,true};
        }

        pair<int,bool>left=solve(root->left);
        pair<int,bool>right=solve(root->right);


        int height=max(left.first,right.first)+1;
        bool ans=left.second&&right.second&&(abs(left.first-right.first)<=1);
        return{height,ans};
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
