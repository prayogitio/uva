#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int set[10][10];
pair<int,int> path[10];
int nmax = 0;

bool valid(int n, int r, int c) {
	for (int i = 0; i < n; i++) {
		if (path[i].first == r || path[i].second == c) return false;
		if (abs(path[i].first - r) == abs(path[i].second - c)) return false;
	}
	return true;
}

void search(int n) {
	if (n == 8) {
		int total = 0;
		for (int m = 0; m < 8; m++) {
			total += set[path[m].first][path[m].second];
		}
		nmax = max(nmax,total);
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (valid(n, i, n)) {
			path[n] = make_pair(i,n);
			search(n+1);
		}
	}
}

int main() {
	int k; scanf("%d", &k);
	while (k--) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				scanf("%d", &set[i][j]);
		nmax = 0;
		search(0);
		printf("%5d\n", nmax);
	}
	return 0;
}