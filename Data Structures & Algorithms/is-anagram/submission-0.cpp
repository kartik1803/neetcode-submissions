class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){
            return false;
        }
        vector<int> count1(26,0);
            for(int i=0;i<s.length();i++){
                int index=s[i]-'a';
                count1[index]++;
            }
           vector<int>count2(26,0);
                for(int i=0;i<t.length();i++){
                    int index=t[i]-'a';
                    count2[index]++;
                }
            
            for (int i=0;i<26;i++){
                if (count1[i]!=count2[i]){
                    return false;
                }
            }
            return true;

        }
        
    };
