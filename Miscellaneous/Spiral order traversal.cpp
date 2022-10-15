#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int str=0,stc=0,edr=n-1,edc=m-1;
    while(str<=edr && stc<=edc)
    {
    	for(int i=stc;i<=edc;i++)
    	{
    		cout<<a[str][i]<<" ";
		}
		str++;
		for(int i=str;i<=edr;i++)
		{
			cout<<a[i][edc]<<" ";
		}
		edc--;
		for(int i=edc;i>=stc;i--)
		{
			cout<<a[edr][i]<<" ";
		}
		edr--;
		for(int i=edr;i>=str;i--)
		{
			cout<<a[i][stc]<<" ";
		}
		stc++;
		
	}
	return 0;
}
