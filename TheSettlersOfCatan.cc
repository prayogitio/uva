	#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int set[30][30];
int ans;
int n, m;

void dfs(int s, int l) {
	if (l > ans) {
		ans = l;
	}
	for (int i = 0; i < n; i++) {
		if (set[s][i]) {
			set[s][i] = 0;
			set[i][s] = 0;
			dfs(i, l+1);
			set[s][i] = 1;
			set[i][s] = 1;
		}
	}
}

int main() {
	while (scanf("%d %d", &n, &m) && n && m) {
		memset(set, 0, sizeof set);
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			set[a][b] = 1;
			set[b][a] = 1;
		}
		ans = 0;
		for (int i = 0; i < n; i++) {
			dfs(i, 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}