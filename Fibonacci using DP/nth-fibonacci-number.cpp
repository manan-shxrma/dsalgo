#include<iostream>
using namespace std;

int fibonacciNumber(int n){
    int dp[n],i;
    dp[0] = 0, dp[1] = 1;
    for(i=0; i<n; i++)
        dp[i] = dp[i-1]+dp[i-2];
    return dp[n-1];
}

int main(int argc, char* argv){
    int n;
    cout<<"Enter n";
    cin>>n;
    cout<<fibonacciNumber(n);
    return 0;
}
   