// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(string s, map<string,int>&m,vector<string>&v,string temp){
        if(s.length()==0){
            temp.pop_back();
            v.push_back(temp);
            return;
        }
        for(int i=0;i<s.length();i++){
            string chk = s.substr(0,i+1);
            if(m[chk]){
                chk+=' ';
                dfs(s.substr(i+1), m, v, temp+chk);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> v;
        map<string,int>m;
        for(auto i : dict) m[i]++;
        
        dfs(s, m, v, "");
        
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
