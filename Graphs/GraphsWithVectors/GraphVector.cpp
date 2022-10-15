#include<iostream>
#include<vector>

using namespace std;

//Data structure to store a Graph Edge
struct Edge{
	int source;
	int destination;

};

//A class to represent the graph object

class Graph{

public:
	//A vector of vectors to represent an Adjencency List
	vector<vector<int>>adjList;

	//Graph Constructor
	Graph(vector<Edge>const &edges,int n){

		//Resize the vector to hold n elements of type vector<int>
		adjList.resize(n);

		//add edges to the directed graph
		for(auto &edge:edges){

		//insert at the end
			adjList[edge.source].push_back(edge.destination);

			//uncomment for undirected Graph
			adjList[edge.destination].push_back(edge.source);
		}

	}


};

void printGraph(Graph const &graph,int n){

	for(int i=0;i<n;i++){

		//print the current index number
		cout<<i<<"-->";

		//print all neighbouring vertices of a vertex i
		for(int v:graph.adjList[i]){
			cout<<v<<" ";
		}
		cout<<endl;


	}


}


// Graph Implementation using STL
int main()
{

	 	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	    #endif
    // vector of graph edges as per the above diagram.
    // Please note that the initialization vector in the below format will
    // work fine in C++11, C++14, C++17 but will fail in C++98.
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
 
    // total number of nodes in the graph (labelled from 0 to 5)
    int n = 6;
 
    // construct graph
    Graph graph(edges, n);
 
    // print adjacency list representation of a graph
    printGraph(graph, n);
 
    return 0;
}
