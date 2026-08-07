class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int pro=1;
            for(int j=0;j<nums.size();j++){
                if(j==i){
                    continue;
                }
                pro=pro*nums[j];
            }
            ans.push_back(pro);
        }
        return ans ;

    }
};
