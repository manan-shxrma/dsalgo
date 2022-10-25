#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    int search(const vector<int>& nums, int n){
        int low=0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == n){
                return mid;
            }
            else if(nums[mid] > n){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> copy = nums;
	    int n = nums.size();
	    sort(nums.begin(),nums.end());
	    int ans = 0;
	    vector<bool> vis(n,false);
	    for(int i= 0;i<n;i++){
	        if(copy[i] == nums[i] || vis[i]==true){
	            vis[i] = true;
	        }
	        else{
	           // cout<<i<<endl;
	            int count = 0;
	            count++;
	            vis[i] = true;
	            int index = search(nums, copy[i]);
	            while(!vis[index]){
	                count++;
	                vis[index] = true;
	               // cout<<index<<" "<<vis[index]<<endl;
	                index = search(nums,copy[index]);
	            }
	            ans = ans+count -1;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
