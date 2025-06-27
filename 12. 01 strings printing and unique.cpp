#include <iostream>
#include <bitset>
using namespace std;

void generateBinaryPermutations(int n) {
    int total = 1 << n;  // 2^n combinations

    for (int i = 0; i < total; ++i) {
        bitset<32> b(i); // assuming n <= 32
        string binary = b.to_string().substr(32 - n); // get last n bits
        cout << binary << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    generateBinaryPermutations(n);
    return 0;
}

|
class Solution {
public:
    unordered_map<string,int>mp; 
    void generateBinaryPermutations(int n) {
    int total = 1 << n;  // 2^n combinations

    for (int i = 0; i < total; ++i) {
        bitset<32> b(i); // assuming n <= 32
        string binary = b.to_string().substr(32 - n); // get last n bits
        mp[binary]++; 
    }
}
    string findDifferentBinaryString(vector<string>& nums) {
         int n=nums[0].length(); 
         generateBinaryPermutations(n);
         for(auto i:nums) mp[i]++; 
         for(auto i:mp) 
         {
            if(i.second==1) return i.first; 
         }     
         return ""; 
    }
};
