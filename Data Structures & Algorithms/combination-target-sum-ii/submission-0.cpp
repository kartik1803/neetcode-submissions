class Solution {
public:
   void solve (vector<int>& candidates,int index,vector<int>&output, vector<vector<int>>&ans ){
            
                ans.push_back(output);
                
            
            for (int i=index ;i<candidates.size();i++){
                if (i>index&&candidates[i]==candidates[i-1]){
                    continue;

                }
                output.push_back(candidates[i]);
                solve (candidates,i+1,output,ans);
                output.pop_back();
            }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(),candidates.end());
        vector<vector<int>>ans ;
        vector<int>output;
        solve (candidates,0,output ,ans);
        vector<vector<int>>finalans;
        for (int i=0;i<ans.size();i++){
            int sum =0;
            for (int j=0;j<ans[i].size();j++){
                sum =sum +ans[i][j];
            }
            if (sum ==target){
                finalans.push_back(ans[i]);
            }
        }
        return finalans;
    
    }
};
 