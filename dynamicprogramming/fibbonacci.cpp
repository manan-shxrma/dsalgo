#include<bits/stdc++.h>
using namespace std;

int fibboncacci(int n)          //Time Complexity = O(2^n)
{
    if(n==0||n==1)  return 1;

    return fibboncacci(n-1)+fibboncacci(n-2);
}

int fibbonacciUsingDP(int n)
{
    vector<int> dp(n+1);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];

    return dp[n];
}

int main()
{
    int n;
    cout<<"\nEnter the number:\t";
    cin>>n;

    cout<<"\nFibbonacci number using recursion:\t"<<fibboncacci(n)<<endl;
    cout<<"\nFibbonacci number using dp:\t"<<fibbonacciUsingDP(n)<<endl;
    return 0;
}