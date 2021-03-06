// Graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void insert(vector<vector<int>>& graph, int v1, int v2) {
	graph[v1].push_back(v2);
	graph[v2].push_back(v1);
}

void printAdjacency(vector<vector<int>>& graph) {
	for (auto k : graph) {
		for (auto i : k) {
			cout << "->"<< i;
		}
		cout << endl;
	}
}

void bfs(vector<vector<int>>& graph, int vertex) {
	vector<bool> vmark(graph.size(), false);
	queue<int> q;
	q.push(vertex);
	vmark[vertex] = true;
	cout << "BFS: ";
	while (!q.empty()) {
		int i = q.front();
		cout << i << " ";
		for (auto k : graph[i]) {
			if (not vmark[k]) {
				q.push(k);
				vmark[k] = true;
			}
		}
		q.pop();
	}
}

int main()
{
	vector<vector<int>> graph(7);
	insert(graph, 1, 2);
	insert(graph, 1, 3);
	insert(graph, 2, 4);
	insert(graph, 2, 5);
	insert(graph, 3, 5);
	insert(graph, 4, 6);
	insert(graph, 4, 5);
	insert(graph, 5, 6);

	//printAdjacency(graph);
	bfs(graph, 2);

    return 0;
}

