#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#define INF 10000000
using namespace std;

int dist[2005];
int V, E;

void bellmanFord(vector<pair<int,pair<int,int>>> adj, int src) {
	bool hasNegativeCycle = false;
	for (int i = 0; i < V; i++) {
		dist[i] = INF;
	}
	dist[src] = 0;
	vector<pair<int,pair<int,int>>>::iterator it;
	for (int i = 0; i < V-1; i++) {
		for (it = adj.begin(); it != adj.end(); it++) {
			int u =	it->second.first;
			int v = it->second.second;
			int w = it->first;
			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}
	for (it = adj.begin(); it != adj.end(); it++) {
		int u =	it->second.first;
		int v = it->second.second;
		int w = it->first;
		if (dist[u] != INF && dist[u] + w < dist[v]) {
			hasNegativeCycle = true;
		}
	}
	if (!hasNegativeCycle) printf("not possible\n");
	else printf("possible\n");
}

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d", &V, &E);
		vector<pair<int,pair<int,int>>> adj;
		for (int i = 0; i < E; i++) {
			int x, y, t;
			scanf("%d %d %d", &x, &y, &t);
			adj.push_back({t,{x,y}});
		}
		bellmanFord(adj, 0);
	}
	return 0;
}