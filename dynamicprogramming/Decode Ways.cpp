//link:https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int solve(int i,string s,int n,vector<int> &dp)
    {
      if(i>=n)
      {
          return 1;
      }
      if(s[i]=='0')
      {
          return 0;
      }
      if(dp[i]!=-1)
      {
          return dp[i];
      }
      //option 1: consider single char
      int ans=solve(i+1,s,n,dp);
      
      //option 2:combine with next character, also check for its boundry value 26
       if(i<n-1 && (s[i]-'0')*10+(s[i+1]-'0')<=26)
       {
           ans+=solve(i+2,s,n,dp);
       }
       //store it in dp array
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
         return solve(0,s,n,dp);
    }
};
