#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>adjacencyMatrixToList(vector<vector<int>>adjacencyMatrix){
	int n=adjacencyMatrix.size();

	vector<vector<int>>adjacencyList(n);

	for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){
			if(adjacencyMatrix[i][j]){
				adjacencyList[i].push_back(j);
			}
		}


	}
	return adjacencyList;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	 vector<vector<int>> adjacencyMatrix {{0, 1, 0}, {1, 0, 1}, {1, 0, 0}};
    auto adjacencyList = adjacencyMatrixToList(adjacencyMatrix);
    cout << "Neighbors of node 1:";
    for (auto u : adjacencyList[1]) {
        cout << " " << u;
    }
    cout << endl;

}
