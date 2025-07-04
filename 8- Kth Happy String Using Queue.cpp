class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > (3 << (n - 1))) return ""; // Check if k is out of bounds
        // k> 3*pow(2,n-1); 
        queue<string> q;
        q.push("");  // Start with an empty string
        
        while (k) {
            string curr = q.front();
            q.pop();
            
            for (char c = 'a'; c <= 'c'; c++) {
                if (curr.empty() || curr.back() != c) {
                    q.push(curr + c);
                    cout<<curr+c<<endl; 
                    if (curr.size() + 1 == n) k--;
                    cout<<k<<endl; 
                }
                if (k == 0) break;
            }
        }

        return q.back();
    }
};
