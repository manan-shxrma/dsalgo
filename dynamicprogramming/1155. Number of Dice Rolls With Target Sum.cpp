class Solution {
public:
   int dp[1001][31];
    int solve(int d,int f,int target)
    {
        if(d==0 && target==0)
        {
            return 1;
        }
        else if(d<=0 || target<=0)
        {
            return 0;
        }
        if(dp[target][d]!=-1)
        {
            return dp[target][d];
        }
        
           int ans=0;
            for(int i=1;i<=f;i++)
            {
                ans=((ans%1000000007)+(solve(d-1,f,target-i)))%1000000007;
            }
               
       
        return  dp[target][d]=ans;
    }
    int numRollsToTarget(int d, int f, int target) {
       dp[target+1][d+1];
        memset(dp,-1,sizeof(dp));
       return solve(d,f,target);
    }
};