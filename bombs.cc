#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#define INF 10000000
using namespace std;

int R, C;
int dist[1005][1005];

bool valid(int rw, int cl) {
	if (rw >= 0 && rw <= R && cl >= 0 && cl <= C) return true;
		return false;
}

void bfs(int init_row, int init_col) {
	queue<int> q;
	q.push(init_row);
	q.push(init_col);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		if (valid(x-1, y) && dist[x-1][y] < 0) {	
			q.push(x-1);
			q.push(y);
			dist[x-1][y] = dist[x][y] + 1;
		}	
		if (valid(x+1, y) && dist[x+1][y] < 0) {
			q.push(x+1);
			q.push(y);
			dist[x+1][y] = dist[x][y] + 1;
		}
		if (valid(x, y+1) && dist[x][y+1] < 0) {
			q.push(x);
			q.push(y+1);
			dist[x][y+1] = dist[x][y] + 1;
		}
		if (valid(x, y-1) && dist[x][y-1] < 0) {
			q.push(x);
			q.push(y-1);
			dist[x][y-1] = dist[x][y] + 1;
		}
	}
}

int main() {
	while (scanf("%d %d", &R, &C) && R && C) {
		for (int i = 0; i < 1005; i++) {
			memset(dist[i], -1, sizeof(dist[i]));
		}
		int row;
		scanf("%d", &row);
		for (int i = 0; i < row; i++) {
			int col;
			scanf("%d", &col);
			int mines;
			scanf("%d", &mines);
			for (int j = 0; j < mines; j++) {
				int l;
				scanf("%d", &l);
				dist[col][l] = INF;
			}
		}
		int init_row, init_col, dest_row, dest_col;
		scanf("%d %d %d %d", &init_row, &init_col, &dest_row, &dest_col);
		dist[init_row][init_col] = 0;
		bfs(init_row, init_col);
		printf("%d\n", dist[dest_row][dest_col]);
	}
	return 0;
}