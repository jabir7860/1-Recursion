class Solution {
public:
    bool dfs(int ind,vector<int>&m,vector<int>&sides,int target) 
    {
          cout<<ind<<endl; 
        if(ind==m.size()) return sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0; 
        for(int i=0;i<4;i++) 
        {
            if(m[ind]<=sides[i]) 
            {
                sides[i]-=m[ind]; 
                if(dfs(ind+1,m,sides,target)) return 1; 
                sides[i]+=m[ind]; 

                if(sides[i]==target) break; 
            }
        }
        return 0; 
    }
    bool makesquare(vector<int>& m) {
        int sum=0; 
        for(auto i:m) sum+=i;
        if(sum%4!=0) return 0; 
        if(m.size()<4) return 0; 
        vector<int>sides(4,sum/4);
        return dfs(0,m,sides,sum/4);  
    }
};
