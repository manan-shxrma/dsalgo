#include<bits/stdc++.h>
// #define '\0' null;
using namespace std;


bool compare(string a,string b){


	if(a.length()==b.length()){
		return a<b; //lexicographic
	}

	return a.length() < b.length();
}


//given a string, find all the subsets of given string
void findSubsets(char *input,char *output,int i, int j,vector<string>&list){

	//base case
	if(input[i]=='\0'){

		output[j]=='\0';
		string temp(output);
		list.push_back(temp);
		// cout<<output<<endl;
		return;
	}

	//recursive case



	//Include the ith letter
	output[j]=input[i];
	findSubsets(input,output,i+1,j+1,list);


	//Exclude the ith letter
	//Overwriting
	output[j]='\0';
	findSubsets(input,output,i+1,j,list);
	//this above call will actually overwrite what was written in the 21rd line

	//we can custom do it too (Line 28)




}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	char input[100];
	char output[100];

	vector<string>list;


	cin>>input;

	findSubsets(input,output,0,0,list);

	sort(list.begin(),list.end(),compare);

	for(auto s:list){
		cout<<s<<",";
	}


	return 0;

}
