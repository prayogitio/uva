#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[105][105];
	bool isPlus = false;
	while (scanf("%d", &N) != EOF) {
		int max_val = -10000000;
		isPlus = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
				if (A[i][j] > 0) isPlus = true;
				max_val = max(max_val, A[i][j]);
				if (j > 0) A[i][j] += A[i][j-1];
			}
		}
		if (isPlus) {
			int subRect, ans = -10000000;
			for (int l = 0; l < N; l++) {
				for (int r = l; r < N; r++) {
					subRect = 0;
					for (int row = 0; row < N; row++) {
						if (l > 0) subRect += A[row][r] - A[row][l-1];
						else subRect += A[row][r];
						if (subRect < 0) subRect = 0;
						ans = max(ans, subRect);
					}
				}
			}
			printf("%d\n", ans);	
		} else {
			printf("%d\n", max_val);
		}
	}
	return 0;
}