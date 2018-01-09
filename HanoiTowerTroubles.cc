#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

bool isSquare(int x) {
	double res1 = sqrt(x);
	int res2 = sqrt(x);
	if (res1 == res2) return true;
	else return false;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		int top[50];
		memset(top, 0, sizeof top);
		int i;
		for (i = 1;; i++) {
			int count = 0;
			for (int j = 0; j < N; j++) {
				if (isSquare(top[j] + i) || top[j] == 0) {
					top[j] = i;
					break;
				}
				count++;
			}
			if (count == N)
				break;
		}
		printf("%d\n", i-1); 
	}
	return 0;
}