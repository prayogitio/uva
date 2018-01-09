#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <limits.h>
#include <map>
using namespace std;

int n; 

bool bfs(int rgraph[105][105], int s, int t, int parent[]) {
	bool visited[105];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++) {
			if (visited[v] == false && rgraph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return (visited[t] == true);
}

int fordFulkerson(int graph[105][105], int s, int t) {
	int rgraph[105][105];
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			rgraph[u][v] = graph[u][v];
		}
	}
	int parent[105];
	int max_flow = 0;
	while (bfs(rgraph, s, t, parent)) {
		int path_flow = INT_MAX;
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			path_flow = min(path_flow, rgraph[u][v]);
		}
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			rgraph[u][v] -= path_flow;
			rgraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main() {
	int x = 1;
	while(scanf("%d", &n) && n) {
		printf("Network %d\n", x++);
		int s,t,c; scanf("%d %d %d", &s, &t, &c);
		int graph[105][105];
		memset(graph, 0, sizeof graph);
		for (int i = 0; i < c; i++) {
			int a,b,d; scanf("%d %d %d", &a, &b, &d); a--; b--;	
			graph[a][b] += d;
			graph[b][a] += d;
		}
		printf("The bandwidth is %d.\n\n", fordFulkerson(graph, s-1,t-1));
	}
	return 0;
}