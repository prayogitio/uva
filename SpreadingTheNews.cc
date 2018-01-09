#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int visited[2505];
int dist[2505];
vector<int>disasta;

void bfs(int t, vector<vector<int>> adj) {
	if (adj[t].size() == 0) {
		printf("0\n");
		return;
	}
	int day = 0;
	queue<int> q;
	q.push(t);
	visited[t] = 1;
	while (!q.empty()) {
		day++;
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (visited[v]) continue;
			if (dist[v] < 0) {
				dist[v] = dist[u] + 1;
				disasta.push_back(dist[v]);
			}
			visited[v] = 1;
			q.push(v);
		}
	}
	/*for (int i = 0; i < disasta.size(); i++) {
		printf("%d ", disasta[i]);
	}*/
	int max = 0;
	for (int i = 0; i < disasta.size(); i++) {
		int my_count = count(disasta.begin(), disasta.end(), i);
		if (max < my_count) {
			max = my_count;
		}
	}
	int first;
	for (int i = 1; i < disasta.size(); i++) {
		int my_count = count(disasta.begin(), disasta.end(), i);
		if (my_count == max) {
			first = i;
			break;
		}
	}
	printf("%d %d\n", max, first);
}

int main() {
	int E;
	vector<vector<int>> adj(2505);
	scanf("%d", &E);
	for (int i = 0; i < E; i++) {
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			int n;
			scanf("%d", &n);
			adj[i].push_back(n);
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 2505; i++) {
			memset(visited, 0, sizeof(visited));
			memset(dist, -1, sizeof(dist));
		}
		disasta.clear();
		disasta.resize(0);
		int t;
		scanf("%d", &t);
		dist[t] = 0;
		disasta.push_back(0);
		bfs(t, adj);
	}
	
	return 0;	
}