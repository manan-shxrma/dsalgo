//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//Shortest code for Kadanes algorithm line 13-23 :)

// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int A[], int n){
        
    int ans = A[0];
    int sum = A[0];
    for(int i =1 ; i<n;i++){
       sum = max(A[i],sum+A[i]);
       ans = max(ans,sum);
    }
    return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
