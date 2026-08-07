class Solution {
public:
void solve (vector<int>& nums,int index,vector<int>&output, vector<vector<int>>&ans){
     if (index==nums.size()){
        ans.push_back(output);
        return ;}
        
    
    output.push_back(nums[index]);
    solve (nums,index+1,output,ans);
    output.pop_back();

    int id=index+1;
    while(id<nums.size()&&nums[id]==nums[id-1]){
        id++;
    }
    solve (nums,id,output,ans);
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>output;
        solve (nums,0,output,ans);
        return ans ;
    }
};
