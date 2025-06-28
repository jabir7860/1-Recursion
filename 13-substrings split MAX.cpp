class Solution {
public:
    int fun(int start,const string& s,unordered_set<string>& seen) 
    {
        if(start==s.size()) return 0; 
        int maxSplits=0; 
        for(int end=start+1;end<=s.size();end++) 
        {
            string substring=s.substr(start,end-start); 
            if(seen.find(substring)==seen.end())
            {
                  cout<<substring<<endl; 
                seen.insert(substring); 
                maxSplits=max(maxSplits,1+fun(end,s,seen)); 
                seen.erase(substring); 
            }
        }
        return maxSplits; 
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>seen; 
        return fun(0,s,seen); 
    }
};
