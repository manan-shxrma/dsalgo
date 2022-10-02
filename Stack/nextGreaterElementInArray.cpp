// In this problem, an integer array is given and for every array element, we have to print next greater element (on its right) in the array.
// If an element doesn't have a greater element on its right, we'll print -1

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	stack<int> s;
	int ans[n];
	for(int i=0;i<n;i++){
		ans[i] = -1;
	}
	for(int i=0;i<n;i++){
		while(!s.empty() && arr[s.top()]<arr[i]){
			ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	cout<<"Next Greater Elements: ";
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
}
