#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr,int n){

	//print our array
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
}


void fillArray(int *arr,int i,int n,int val){

	//base case
	if(i==n){

		printArray(arr,n);
		cout<<endl;
		
		return;
	}


	//recursive case
	arr[i]=val;
	fillArray(arr,i+1,n,val+1);

	//backtracking step

	arr[i]=-1*arr[i];


}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int arr[100]={0};

	int n;
	cin>>n;

	fillArray(arr,0,n,1);
	printArray(arr,n);

}
