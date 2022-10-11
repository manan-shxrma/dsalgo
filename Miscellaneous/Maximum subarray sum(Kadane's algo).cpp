#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n;
	cout<<"Enter length of array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int currsum=0;
	int mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		currsum=currsum+a[i];
	    if(currsum<0)
	    {
	    	currsum=0;
		}
		mx=max(mx,currsum);
		
	}
	cout<<"Your maximum subarray sum is "<<mx;
	return 0;
	
}
