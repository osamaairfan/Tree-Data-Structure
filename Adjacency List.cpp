
//Undirected Graph using adjacency List
#include <iostream>
#include <vector>
using namespace std;

const int V = 6;
//Method: Array of Vectors - vector<int> graph[V]

class Graph {
public:

	void addEdge(vector<int> graph[], int source, int destination) {
		graph[source].push_back(destination);
		graph[destination].push_back(source);
	}

	void printGraph(vector<int> graph[]) {
		for (int source = 0; source < V; source++) {
			cout << "Number of Edges for " << source << " are: " << graph[source].size() << endl;
			for (int neighbour : graph[source]) {
				cout << source << "  " << neighbour << endl;
			}
		}
	}
};

int main() {
	//Declares adjacency list
	vector<int> graph[V];
	Graph g1;
	g1.addEdge(graph, 0, 1);
	g1.addEdge(graph, 0, 5);
	g1.addEdge(graph, 1, 5);
	g1.addEdge(graph, 1, 2);
	g1.addEdge(graph, 2, 4);
	g1.addEdge(graph, 3, 5);
	g1.addEdge(graph, 3, 4);
	g1.printGraph(graph);
}