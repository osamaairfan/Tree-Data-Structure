
//Undirected Graph using adjacency Matrix
#include <iostream>
using namespace std;

const int V = 5;

class Graph {
public:
	void printGraph(int graph[][V]) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
	}

	void createMatrix(int graph[][V]) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				graph[i][j] = 0;
				if (i == j) {
					graph[i][j] = 1;
				}
			}
		}
	}
};

int main() {
	Graph g1;

	int graph[V][V];

	g1.createMatrix(graph);

	graph[0][1] = 1;
	graph[1][0] = 1;
	graph[1][4] = 1;
	graph[4][1] = 1;
	graph[1][3] = 1;
	graph[3][1] = 1;
	graph[2][3] = 1;
	graph[3][2] = 1;

	g1.printGraph(graph);
	
}