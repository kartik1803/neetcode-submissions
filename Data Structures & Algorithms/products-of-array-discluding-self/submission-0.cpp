class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>t1;
        for (int i=0;i<nums.size();i++){
            int pro=1;
            for (int j=0;j<nums.size();j++){
            
            if (j==i){
                continue;
            }
            else{
                pro*=nums[j];
            }

        }
        t1.push_back(pro);

        }
        return t1;

    }
};
