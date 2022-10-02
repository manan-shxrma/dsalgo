#include<bits/stdc++.h>
using namespace std;

//given a string, find all permutations of the string

void permutations(string s,int i){

	//base case
	if(i==s.length()){
		cout<<s<<endl;
		return;
	}

	//recursive case
	for(int j=i;j<int(s.length());j++){
		swap(s[i],s[j]);
		permutations(s,i+1);
		swap(s[i],s[j]);
	}
	return;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s="abc";
	int i=0;

	permutations(s,i);

	return 0;

}
