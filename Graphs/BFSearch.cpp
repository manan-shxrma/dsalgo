#include<bits/stdc++.h>
using namespace std;


class Graph{

int V;
list<int>*l;


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

	void bfs(int source){

		queue<int>q;

		//Maintain whether a node has been visited or not
		bool *visited =new bool [V]{0};

		q.push(source);
		visited[source]=true;

		while(!q.empty()){

			//Do some work for every node
			int f=q.front();
			cout<<f<<endl;
			q.pop();

			//Push the nbrs of current node inside q if they are not already visited

			for(auto nbr:l[f]){

				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr]=true;
				}
			}



		}

	}

};



int main(){

	 	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	    #endif

	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);

	g.bfs(1);
	return 0;



}