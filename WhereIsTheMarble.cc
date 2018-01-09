#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, q; int c = 1;
	while (scanf("%d %d", &n, &q) && n && q) {
		vector<int> set;
		printf("CASE# %d:\n", c++);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			set.push_back(x);
		}
		sort(set.begin(), set.end());
		for (int i = 0; i < q; i++) {
			int find; scanf("%d", &find);
			int awal = 0;
			int akhir = set.size()-1;
			bool isFound = false;
			while (awal <= akhir) {
				int mid = (awal+akhir)/2;
				if (set[mid] == find) {
					int pos = lower_bound(set.begin(), set.end(), find) - set.begin();
					printf("%d found at %d\n", find, pos+1);
					isFound = true;
					break;
				}
				if (find < set[mid]) akhir = mid-1;
				if (find > set[mid]) awal = mid+1;
			}
			if (!isFound) printf("%d not found\n", find);
		}
	}
	return 0;
}
