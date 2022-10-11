class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0) return 0;
        vector<vector<int>> dp(k+1,vector<int>(2));
        for(int i=0;i<=k;i++) dp[i][0] = INT_MAX;
        for(auto& price : prices){
            for(int i=1;i<=k;i++){
                dp[i][0] = min(dp[i][0], price-dp[i-1][1]);
                dp[i][1] = max(dp[i][1],price-dp[i][0]);
            }
        }
        return dp[k][1];
    }
};
