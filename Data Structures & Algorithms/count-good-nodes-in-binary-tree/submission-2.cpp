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
    void solve(TreeNode*root,int &count,int maxval){
        if(root==NULL){
            return ;
        }
       
     
        if(maxval<=root->val){
            count++;
            maxval=root->val;
        }
solve(root->left,count,maxval);
solve(root->right,count,maxval);

    }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        solve(root,count,INT_MIN);
        return count;

    }
};
