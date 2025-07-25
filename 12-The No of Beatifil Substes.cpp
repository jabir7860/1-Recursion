https://leetcode.com/problems/the-number-of-beautiful-subsets/

https://leetcode.com/problems/the-number-of-beautiful-subsets/

class Solution {
public:
    int dfs(vector<int>&nums,int idx,int k,unordered_map<int,int>&mp){
        if(idx==nums.size()) return 1; 
        int taken=0; 
        if(!mp[nums[idx]-k] && !mp[nums[idx]+k])
        {
            mp[nums[idx]]++; 
            taken=dfs(nums,idx+1,k,mp); 
            mp[nums[idx]]--; 
        }
        int nt=dfs(nums,idx+1,k,mp); 
        return taken+nt;  
    }
    int beautifulSubsets(vector<int>& nums, int k){
        unordered_map<int,int>mp; 
        int ans=dfs(nums,0,k,mp); 
        return ans-1; 
    }
};
