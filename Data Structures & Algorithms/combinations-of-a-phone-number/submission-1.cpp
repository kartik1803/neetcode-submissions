class Solution {
public:
void solve (string digits,int index ,vector<string>&ans,string output,string mapp[]){
    if (index==digits.size()){
        ans.push_back(output);
        return ;
    }
    
    int digit=digits[index]-'0';
    string final=mapp[digit];
    for (int i=0;i<final.size();i++){
        output.push_back(final[i]);
        solve(digits,index+1,ans,output,mapp);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if (digits.size()==0){
            return ans ;
        }
        string output="";
        string mapp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,ans,output,mapp);
        return ans ;
    }
};
