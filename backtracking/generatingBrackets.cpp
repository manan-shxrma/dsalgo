#include<bits/stdc++.h>
using namespace std;

//Write a function to generate all possible n pairs of balanced parentheses '(' and ')'
//https://leetcode.com/problems/generate-parentheses/

void generateBrackets(string output,int n,int open,int close,int i){

	//i denotes at which index we are present
	if(i==2*n){

		cout<<output<<endl;
		return;
	}

	//open
	if(open<n){
		generateBrackets(output+'(',n,open+1,close,i+1);
	}


	//closing
	if(close<open){
		generateBrackets(output+')',n,open,close+1,i+1);

	}



}



int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	string output;
	int n;
	cin>>n;
	generateBrackets(output,n,0,0,0);

}
