#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, d, r;
	while (scanf("%d %d %d", &n, &d, &r) && (n||d||r)) {
		vector<int> A;
		vector<int> B;
		int dt;
		for (int i = 0; i < n; i++) {
			scanf("%d", &dt); A.push_back(dt);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &dt); B.push_back(dt);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		reverse(B.begin(), B.end());
		int S = 0;
		for (int i = 0; i < n; i++) {
			S += max(0, A[i] + B[i] - d) * r;
		}
		printf("%d\n", S);
	}
	return 0;
}