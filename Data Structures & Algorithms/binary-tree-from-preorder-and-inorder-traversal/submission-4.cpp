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
int from(vector<int>&inorder,int element){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int s,int e,int& index){
        if(s>e||index>=preorder.size()){
            return NULL;
        }
        int element=preorder[index++];
        int getindx=from(inorder,element);
        TreeNode*first=new TreeNode(element);
        first->left=solve(preorder,inorder,s,getindx-1,index);
        first->right=solve(preorder,inorder,getindx+1,e,index);
        return first;

        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return solve(preorder,inorder,0,inorder.size()-1,index);
    }
};
