#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int P[1005];
int W[1005];
int MW[105];
int memo[1005][1005];

int knapsack(int src, int w) {
	if (src == N || w == 0)
		return 0;
	if (memo[src][w] != -1)
		return memo[src][w];
	if (W[src] > w)
		return memo[src][w] = knapsack(src+1, w);
	return memo[src][w] = max(knapsack(src+1, w), P[src] + knapsack(src+1, w-W[src]));
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &P[i], &W[i]);
		}
		int G;
		scanf("%d", &G);
		int sum = 0;
		for (int i = 0; i < G; i++) {
			scanf("%d", &MW[i]);
			memset(memo, -1, sizeof(memo));
			int result = knapsack(0, MW[i]);
			sum += result;
		}
		printf("%d\n", sum);
	}
	return 0;
}