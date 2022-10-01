#include<bits/stdc++.h>
using namespace std;


class Graph{

	list<int>*l;
	int V;

public:
	Graph(int v){
		v=V;
		l=new list<int>[V];
	}

	void addEdge(int x,int y){

		l[x].push_back(y);
	}

	//Complete this method
	void topological_sort(){
		vector<int>indegree(V,0);

		for(int i=0;i<V;i++){

			for(auto nbr:l[i]){
				indegree[nbr]++;
			}
		}
		//bfs
		queue<int>q;

		for(int i=0;i<V;i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}
		while(!q.empty()){
			int node=q.front();
			cout<<node<<" ";
			q.pop();


			for(auto nbr:l[node]){
				indegree[nbr]--;

				if(indegree[nbr]==0){
					q.push(nbr);
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
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(1,4);
	g.addEdge(1,2);

	g.topological_sort();

	return 0;
}