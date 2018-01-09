#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited;
priority_queue<pair<int,int>> pq;

void process(int vtx, const vector<vector<pair<int,int>>>& adj) {
	visited[vtx] = 1;
	for (int i = 0; i < adj[vtx].size(); i++) {
		pair<int,int> v = adj[vtx][i];
		if (!visited[v.first])
			pq.push({-v.second, -v.first});
	}
}

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) && n && m) {
		vector<vector<pair<int,int>>> adj(n);
		visited.assign(n, 0);
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int x, y, z; scanf("%d %d %d", &x, &y, &z);
			adj[x].push_back({y,z});
			adj[y].push_back({x,z});
			sum += z;
		}
		process(0, adj);
		int mst_cost = 0;
		while (!pq.empty()) {
			pair<int, int> front = pq.top(); pq.pop();
			int u = -front.second;
			int w = -front.first;
			if (!visited[u]) {
				mst_cost += w;
				process(u, adj);
			}
		}
		printf("%d\n", sum - mst_cost);
	}
	return 0;
}