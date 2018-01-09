#include <cstdio>
#include <vector>
using namespace std;

int n; 

int withdraw(vector<int> &set) {
	int sum = 0;
	int ans = 1;
	for (int i = 0; i < set.size()-1; i++) {
		printf("%d ", ans);
		if (set[i] + sum < set[i+1]) {
			sum += set[i];
			ans++;
		}
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		vector<int> set;
		for (int j = 0; j < n; j++) {
			int dt; scanf("%d", &dt);
			set.push_back(dt);
		}
		int res = withdraw(set);
		printf("%d\n", res);
	}
	return 0;
}