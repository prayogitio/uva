#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[105][105];
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
				if (i > 0) A[i][j] += A[i-1][j];
				if (j > 0) A[i][j] += A[i][j-1];
				if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
			}
		}
		int maxSubRect = -10000000;
		int subRect;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = i; k < N; k++) {
					for (int l = j; l < N; l++) {
						subRect = A[k][l];
						if (i > 0) subRect -= A[i-1][l];
						if (j > 0) subRect -= A[k][j-1];
						if (i > 0 && j > 0) subRect += A[i-1][j-1];
						maxSubRect = max(maxSubRect,subRect);
					}
				}
			}
		}
		printf("%d\n", maxSubRect);
	}	
}