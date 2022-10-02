#include<bits/stdc++.h>
using namespace std;

int gridWays(int i,int j,int m,int n){

	//Base case
	if(i==m-1 && j==n-1){
		return 1;
	}

	if(i>=m || j>=n){
		return 0;
	}


int ans=gridWays(i+1,j,m,n)+gridWays(i,j+1,m,n);

	return ans;

}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int m,n;
	cin>>m>>n;

	cout<<gridWays(0,0,m,n)<<endl;

}
