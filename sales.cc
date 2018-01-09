#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		vector<int> sales;
		vector<int> res;
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int d;
			scanf("%d", &d);
			sales.push_back(d);
		}	
		for (int i = 1; i < sales.size(); i++) {
			int sum = 0;
			for (int j = 0; j < i; j++) {
				if (sales[j] <= sales[i]) {
					sum++;
				}
			}
			res.push_back(sum);
		}
		int hasil = 0;
		for (int i = 0; i < res.size(); i++) {
			hasil += res[i];
		}
		printf("%d\n", hasil);
	}
	return 0;
}