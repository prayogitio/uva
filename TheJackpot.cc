#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[10005];
	while (scanf("%d", &N) && N) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		int ans = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			sum = sum + A[i];
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		if (ans > 0) printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}
	return 0;
}