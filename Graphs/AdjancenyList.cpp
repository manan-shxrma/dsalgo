#include<iostream>
#include<list>
using namespace std;

class Graph{

int V;
list<int>*l; //Dynamic Allocation //Declaration
//This is a pointer to an array of lists


public:
	Graph(int v){
		V=v;
		l=new list<int>[V];
	}


	void addEdge(int i,int j,bool undir=true){

		l[i].push_back(j);

		if(undir){
			l[j].push_back(i);
		}

	}

	void printAdjList(){

		//Iterate over all the rows
		for(int i=0;i<V;i++){

			cout<<i<<"-->";

			for(auto node:l[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}



};



int main(){

	 	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	    #endif

	Graph g(10);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);


	//Trial method
	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(1,4);
	// g.addEdge(1,5);
	// g.addEdge(1,6);
	// g.addEdge(1,7);
	




	g.printAdjList();

	return 0;
}