#include<iostream>
using namespace std;
void swap(int a[],int c,int b)
{
	int temp;
	temp=a[c];
	a[c]=a[b];
	a[b]=temp;
}
void dnf(int a[],int n)
{
	int low=0;
	int mid=0;
	int high=n-1;
	while(mid<=high)
	{
	   if(a[mid]==0)
	   {
	   	swap(a,low,mid);
	   	low++;
	   	mid++;
	   }
	   else if(a[mid]==1)
	   {
	   	mid++;
	   }
	   else
	   {
	   	swap(a,high,mid);
	   	high--;
	   }
	}
}
int main()
{
	int a[]={0,1,1,0,2,2,1,0,1};
	dnf(a,9);
	for(int i=0;i<9;i++)
	{
		cout<<a[i]<<" ";
	}
}
