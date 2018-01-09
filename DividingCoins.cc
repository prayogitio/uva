#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int c[105];
int memo[105][25005];
int n,m;

int knapsack(int src, int w) {
	/*if (max_val == 0 || max_val < 0)
		return 0;
	if (src == m)
		return 0;
	if (memo[src] != -1) return memo[src];
	if (c[src] > max_val)
		memo[src] = knapsack(src+1, max_val);
	if (c[src] <= max_val) {
		memo[src] = max(knapsack(src+1, max_val), c[src] + knapsack(src+1, max_val - c[src]));
	}
	return memo[src];*/
 	if (src == m || w == 0) 
 		return 0;
  	if (memo[src][w] != -1) 
  		return memo[src][w];
  	if (c[src] > w)         
  		return memo[src][w] = knapsack(src + 1, w);
  	return memo[src][w] = max(knapsack(src + 1, w), c[src] + knapsack(src + 1, w - c[src]));
}

int main() {
	scanf("%d", &n); 
	while (n--) {
		scanf("%d", &m);
		int sum = 0;
		for (int i = 0; i < 105; i++) 
			for (int j = 0; j < 25005; j++)
				memo[i][j] = -1;
		for (int i = 0; i < m; i++) {
			scanf("%d", &c[i]);
			sum += c[i];
		}
		int res = knapsack(0, sum/2);
		printf("%d\n", sum-(2*res));
	}
	return 0;
}