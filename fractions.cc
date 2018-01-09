#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int,int>> s;

int main() {
	int k;
	while (scanf("%d", &k) == 1) {
		int jumlah = 0;
		s.clear();
		for (int i = k+1; i <= k*2; i++) {
			if ((i * k) % (i - k) == 0) {
				jumlah++;
				s.push_back(make_pair((i*k) / (i-k), i));
			}
		}
		printf("%d\n", jumlah);
		for (int i = 0; i < jumlah; i++) {
			printf("1/%d = 1/%d + 1/%d\n", k, s[i].first, s[i].second);
		}
	}
	return 0;
}