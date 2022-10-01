#include<iostream>
#include<vector>
using namespace std;

int main(){

	int n=4;
	vector<vector<int>>adjacencyMatrix(n,vector<int>(n,0));

	//add edges
	vector<pair<int,int>>edges={{0,1},{1,0},{1, 2}, {1, 3}, {2, 0}, {2, 3}};


	for(auto [u,v]:edges){
		adjacencyMatrix[u][v]=1;
	}

	cout<<"Edge from 0 to 1: "<<adjacencyMatrix[0][1]<<endl;




}


// Instead of a nested vector of vectors, we can use a single vector with n*n
// n∗n
//  entries, where A[i, j]
// A[i,j]
//  is stored at index n*i+j
// n∗i+j
// .
// Instead of a vector<int>, we can use a vector<bool>, which stores only one bit per entry



class AdjacencyMatrix {
private:
    vector<bool> adj;
    int n;
public:
  AdjacencyMatrix(int _n) 
      : n {_n} 
      , adj {vector<bool>(_n*_n, 0)}
  {}
  void addEdge(int source, int target) {
      this->adj[this->n * source + target] = true;
  }
  void removeEdge(int source, int target) {
      this->adj[this->n * source + target] = false;
  }
  bool getEdge(int source, int target) {
      return this->adj[this->n * source + target];
  }
};

int main_32t() {
    int n = 4;
    AdjacencyMatrix adjacencyMatrix(n); // create empty matrix

    // add edges using a loop over a vector of (source, target) pairs
    vector<pair<int, int>> edges {{0, 1}, {1, 0}, {1, 2}, {1, 3}, {2, 0}, {2, 3}};
    for (auto [u, v] : edges) {
        adjacencyMatrix.addEdge(u, v);
    }
    cout << boolalpha; // print booleans as true / false
    cout << "Edge from 0 to 1: " << adjacencyMatrix.getEdge(0, 1) << endl;
    cout << "No edge from 0 to 3: " << adjacencyMatrix.getEdge(0, 3) << endl;
    
}