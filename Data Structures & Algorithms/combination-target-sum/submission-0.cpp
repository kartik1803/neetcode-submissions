class Solution {
public:
void solve (vector<int>& nums,int index,vector<vector<int>>&ans, vector<int>&output,int target){
    if (target==0){
        ans.push_back(output);
        return ;
    }
    if (target<0||index>=nums.size()){
        return ;
    }
    output.push_back(nums[index]);
    solve(nums,index,ans,output,target-nums[index]);
    output.pop_back();
    solve(nums,index+1,ans,output,target);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums,0,ans,output ,target);
        return ans ;
    }
};
