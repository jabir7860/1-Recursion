1079. Letter Tile Possibilities : https://leetcode.com/problems/letter-tile-possibilities/description/
Solved
Medium
Topics
premium lock icon
Companies
Hint
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end()); 
        vector<int>used(tiles.length(),0); 
        return fun(tiles,used); 
    }
    int fun(string tiles,vector<int>&used) 
    {
        int count=0; 
        for(int i=0;i<tiles.length();i++) 
        {
            if(used[i]==1 || (i>0 && tiles[i]==tiles[i-1] && used[i-1]==0)){
                continue; 
            }
            else{
                used[i]=1; 
                count=count+1+fun(tiles,used); 
                used[i]=0; 
            }
        }
        return count; 
    }
};
