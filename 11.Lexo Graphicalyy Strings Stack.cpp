class Solution {
public:
    string smallestNumber(string pattern) {
        string res=""; 
        stack<int>st; 
        int n=pattern.length(); 
        for(int i=1;i<=n+1;i++) 
        {
            st.push(i); 
            char c=pattern[i-1]; 
            if(i==n+1 || c=='I') 
            {
                while(!st.empty()) 
                {
                    res.push_back(char('0'+st.top())); 
                    st.pop(); 
                }
            }
        }
        return res; 
    }
};
