class Solution {
public:
    void solve(string digit,string output,int ind,vector<string>&ans,string mapping[]) 
    {
        if(ind==digit.length()) 
        {
            ans.push_back(output); 
            return; 
        }
        for(int i=0;i<mapping[digit[ind]-'0'].length();i++) 
        {
            solve(digit,output+mapping[digit[ind]-'0'][i],ind+1,ans,mapping); 
        }
    }
    vector<string> letterCombinations(string digit) {
        vector<string> ans;
        if (digit.length() == 0) {
            return ans;
        }
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digit,"",0, ans, mapping);
        return ans;
    }
};
