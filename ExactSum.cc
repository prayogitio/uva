#include <cstdio>
#include <limits.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		int set[10000];
		memset(set, 0, sizeof set);
		for (int i = 0; i < n; i++) {
			scanf("%d", &set[i]);
		}
		sort(set, set+n);
		int M; scanf("%d\n", &M);
		pair<int,int> res;
		res = make_pair(0,0);
		int min_diff = INT_MAX;
		for (int i = 0; i < n-1; i++) {
			int to_find = M - set[i];
			int awal = i+1;
			int akhir = n;
			bool found = false;
			while (awal <= akhir && !found) {
				int mid = (awal+akhir)/2;
				if (set[mid] == to_find) {
					if (min_diff > abs(set[i] - set[mid]))
						if (set[i] <= set[mid]) {
							min_diff = abs(set[i] - set[mid]);
							res.first = set[i];
							res.second = set[mid];
						} else {
							res.first = set[mid];
							res.second = set[i];
						}
					found = true;
				}
				if (set[mid] < to_find) {
					awal = mid+1;
				}
				if (set[mid] > to_find) {
					akhir = mid-1;
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n", res.first, res.second);
				printf("\n");
	}
	return 0;
}