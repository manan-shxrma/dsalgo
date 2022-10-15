#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> adjacencyListToMatrix(vector<vector<int>> adjacencyList) {
    // your code here

    int n=adjacencyList.size();
    vector<vector<int>> adjacencyMatrix(n,vector<int>(n,0));


    // for(int i=0;i<n;i++){
    // 	for(int j=0;j<adjacencyList[i].size();j++){
    // 		adjacencyMatrix[i][j]=1;

    // 	}
    // }

    // for(int i=0;i<n;i++){
    // 	for(auto j:adjacencyList[i]){
    // 		adjacencyMatrix[i][j]=1;
    // 	}
    // }

    return adjacencyMatrix;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

}
