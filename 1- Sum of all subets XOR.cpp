1863 : https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/ 

Brute Force : 
Generating all the subsets
Find XOR of each subset 
sum up them. 

  1.how to generate all the subsets; 
  2. no of subsets for any is 2^n; 
  3.  where n is size of array; 


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();

    // Total subsets = 2^n
    vector<vector<int>>ans; 
    for (int i = 0; i < (1 << n); ++i) 
    {
        vector<int> subset;

        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        ans.push_back(subset); 
    }
    cout<<"Printing subsets : "<<endl; 
    for(auto i:ans) 
    {
        for(auto j:i) 
        {
            cout<<j<<" "; 
        }
        cout<<endl; 
    }
    
    cout<<"Size : "<<ans.size()<<endl; 
    return 0;
}


TC : O(N*2^N) 


#include <iostream>
#include <vector>
using namespace std;

vector<int> subset;

void fun(int ind, vector<vector<int>> &ans, vector<int> &nums)
{
    if (ind == nums.size()) {
        ans.push_back(subset); // push the current subset
        return;                // IMPORTANT: return after pushing
    }

    // Pick the element
    subset.push_back(nums[ind]);
    fun(ind + 1, ans, nums);

    // Don't pick the element
    subset.pop_back();
    fun(ind + 1, ans, nums);
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans;

    fun(0, ans, nums);

    cout << "Printing subsets:\n";
    for (auto &i : ans) {
        cout << "{ ";
        for (int j : i)
            cout << j << " ";
        cout << "}\n";
    }

    cout << "Total subsets: " << ans.size() << endl;
    return 0;
}
