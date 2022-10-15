
#include<bits/stdc++.h>
using namespace std;

class Node{

public:
	string name;
	list<string>nbrs;

	Node(string name){
		this->name=name;
	}


};

class Graph{

//All Nodes

//Hashmap(String,Node*);

unordered_map<string,Node*>mp;

public:
	Graph(vector<string>cities){

		for(auto city:cities){
			//Initialising new node and storing it in an unordered map

			mp[city]=new Node(city);
		}

	}

	void addEdge(string x,string y,bool undir=false){

		mp[x]->nbrs.push_back(y);

		if(undir){
			mp[y]->nbrs.push_back(x);
		}

	}

	void printAdjList(){
		for(auto cityPair:mp){
			auto city=cityPair.first;
			Node *node=cityPair.second;
			cout<<city<<"-->";
			for(auto nbr:node->nbrs){
				cout<<nbr<<",";
			}
			cout<<endl;

		}
	}

};


int main(){

vector<string>cities={"Delhi","Mumbai","Kolkata","Chennai","Nagpur","Shimla"};

Graph g(cities);
g.addEdge("Delhi","Nagpur");
g.addEdge("Nagpur","Delhi");
g.addEdge("Delhi","Shimla");
g.addEdge("Mumbai","Nagpur");
g.addEdge("Mumbai","Delhi");
g.addEdge("Nagpur","Chennai");
g.addEdge("Nagpur","Mumbai");
g.addEdge("Shimla","Kolkata");
g.addEdge("Chennai","Mumbai");
g.addEdge("Nagpur","Kolkata");
g.addEdge("Kolkata","Chennai");


g.printAdjList();


return 0;





}