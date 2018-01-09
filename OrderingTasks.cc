#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visited(100);
stack<int> cetak;
int count = 0;

void dfs(int u, vector<vector<int>> &data) {
	visited[u] = 1;
	for (int i = 0; i < data[u].size(); i++) {
		int v = data[u][i];
		if (!visited[v]) dfs(v, data);
	}
	cetak.push(u+1);
}

int main() {
	int n, m;
	while(scanf("%d %d", &n, &m)==2 && n) {
		vector<vector<int>> data(100);
		fill(visited.begin(), visited.end(), false);
		while(m--) {
			int i, j;
			scanf("%d %d", &i, &j);
			data[i-1].push_back(j-1);
		}
		for (int b = 0; b < n; b++) {
			if (!visited[b]) dfs(b, data);
		}
		int c = 0;
		while (!cetak.empty()) {
			if (c == 0) {
				printf("%d", cetak.top());
				cetak.pop();	
			} else {
				printf(" %d", cetak.top());
				cetak.pop();
			}
			c++;
		}
		printf("\n");		
	}	
	return 0;
}