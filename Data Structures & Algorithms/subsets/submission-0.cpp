class Solution {
public:
void solve (vector<int>&nums,int index,vector<vector<int>>&ans,vector<int>&output){
    if (index>=nums.size()){
        ans.push_back(output);
        return ;
    }
    solve (nums,index+1,ans,output);
    output.push_back(nums[index]);
    solve (nums,index+1,ans,output);
    output.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        solve (nums,0,ans,output);
        return ans ;
    }
};
