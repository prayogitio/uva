#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 10000000
using namespace std;

int dist[20005];
int n, m, S, T;

void dijkstra(vector<vector<pair<int,int>>> adj, int src, int &count_cases) {
	for (int i = 0; i < 20005; i++)
		dist[i] = INF;
	dist[src] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, src});
	vector<pair<int,int>>::iterator it;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (it = adj[u].begin(); it != adj[u].end(); it++) {
			int v = it->second;
			int w = it->first;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	if (dist[T] == INF) 
		printf("Case #%d: unreachable\n", count_cases);
	else 
		printf("Case #%d: %d\n", count_cases, dist[T]);
	count_cases++;
}

int main() {
	int N;
	int count_cases = 1;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d %d %d", &n, &m, &S, &T);
		vector<vector<pair<int,int>>> adj(n);
		while (m--) {
			int s, d, w;
			scanf("%d %d %d", &s, &d, &w);
			adj[s].push_back({w,d});
			adj[d].push_back({w,s});
		}
		dijkstra(adj,S,count_cases);
	}
	return 0;
}