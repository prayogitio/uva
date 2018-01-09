#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char path[100][100];
int x[] = {-1,0,1};
int y[] = {0,-1,0};
string direction[] = {"left", "forth", "right"};
char route[] = {'I','E','H','O','V','A','#'};

void dfs(int src, int i, int j) {
	if (path[i][j] == '#') {
		cout << endl;
		return;
	}
	for (int k = 0; k < 3; k++) {
		if (j + x[k] >= 0 && j + x[k] < m && i + y[k] >= 0) {
			if (path[i+y[k]][j+x[k]] == route[src]) {
				cout << direction[k];
				if (src < 6) {
					cout << " ";
				}
				dfs(src + 1, i + y[k], j + x[k]);
			}
		}
	}
}

int main() {
	int T, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> path[i][j];
				if (path[i][j] == '@') {
					a = i; b = j;
				}
			}
		}
		dfs(0, a, b);
	}
}