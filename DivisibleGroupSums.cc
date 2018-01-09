#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 205
using namespace std;

int set[205];
int memo[MAX][MAX][15];
int N,Q,M,D;

int dp(int i, int sum, int c) {
	if (c == M && sum == 0) 
		return 1;
	if (c == M && sum != 0)	
		return 0;
	if (i == N)	
		return 0;
	if (memo[i][sum][c] != -1) 
		return memo[i][sum][c];
	memo[i][sum][c] = dp(i+1, sum%D, c) + dp(i+1, (sum+set[i])%D, c+1);
	
	return memo[i][sum][c];
}

int main() {
	int res;
	int x=1;
	while (scanf("%d %d", &N, &Q) && N && Q) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &set[i]);
		}
		printf("SET %d:\n", x++);
		for (int k = 0; k < Q; k++) {
			scanf("%d %d", &D, &M);
			memset(memo, -1, sizeof(memo));
			res = dp(0,0,0);
			printf("QUERY %d: %d\n", k+1, res);
		}
	}	
	return 0;
}