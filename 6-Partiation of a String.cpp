// Printing all Partitions of string 
#include<bits/stdc++.h> 
using namespace std; 
void fun(int ind,vector<vector<string>>&res,vector<string>path,string s) 
{
    if(ind==s.size()) 
    {
        res.push_back(path); 
        return; 
    }
    for(int i=ind;i<s.size();i++) 
    {
            path.push_back(s.substr(ind,i-ind+1));
            fun(i+1,res,path,s); 
            path.pop_back(); 
    }
}
int main() 
{
    string s="abcd"; 
    vector<vector<string>>res; 
    vector<string>path; 
    fun(0,res,path,s);
    cout<<res.size()<<endl; 
    for(auto i:res) 
    {
        for(auto j:i) 
        {
            cout<<j<<" "; 
        }
        cout<<endl; 
    }
    
}
