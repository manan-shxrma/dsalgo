#include<bits/stdc++.h>
using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n=4;
	vector<vector<int>>adjacencyMatrix(n,vector<int>(n,0));


	vector<tuple<int,int,int>>edges{

		make_tuple(0,1,5),
		make_tuple(1,0,3),
		make_tuple(1,2,7),
		make_tuple(1,3,4),
		make_tuple(2,0,11),
		make_tuple(2,3,4)

	};
	for(auto [v,u,w]:edges){
		adjacencyMatrix[v][u]=w;

	}
	cout << "Edge from 0 to 1: weight " << adjacencyMatrix[0][1] << endl;
    cout << "No edge from 0 to 3: " << adjacencyMatrix[0][3] << endl;	

}
