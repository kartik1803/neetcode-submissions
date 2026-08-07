class Solution {
public:
void solve (int open ,int close,vector<string>&ans,string output ){
    if (open ==0&&close==0){
        ans.push_back(output);
        return ;

    }
    if (open>0){
        
        solve(open-1,close,ans,output+"(");
    }
    if (close>open){
        
        solve(open,close-1,ans,output+")");
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output="";
        solve (n,n,ans,output);
        return ans ;
    }
};
