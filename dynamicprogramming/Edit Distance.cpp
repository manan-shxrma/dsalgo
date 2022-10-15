//link:https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int solve(string &word1, string &word2,int m,int n, vector<vector<int>> &dp)
    {
        if(m==0)
        {
            return n;
        }
        else if(n==0)
        {
            return m;
        }
        else if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        //if equal then no operation
        else if(word1[m-1]==word2[n-1])
        {
            return dp[m][n]= solve(word1,word2,m-1,n-1,dp);
        }
        //if not equal then take min of inserting,deleting and replacing
        else
        {
            return dp[m][n]=1+min(solve(word1,word2,m-1,n-1,dp),min(solve(word1,word2,m-1,n,dp),solve(word1,word2,m,n-1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,m,n,dp);
    }
};