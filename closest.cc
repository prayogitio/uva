#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int kasus = 1;
	while (scanf("%d", &n) && n) {
		vector<int> data;
		vector<int> jumlah_data;
		for (int k = 0; k < n; k++) {
			int num;
			scanf("%d", &num);
			data.push_back(num);
		}
		for (int i = 0; i < data.size()-1; i++) {
			for (int j = i+1; j < data.size(); j++) {
				jumlah_data.push_back(data[i] + data[j]);
			}
		}
		int m;
		scanf("%d", &m);
		printf("Case %d:\n", kasus);
		kasus++;
		while (m--) {
			int cari;
			scanf("%d", &cari);
			int q = cari;
			int dis = abs(jumlah_data[0] - q);
			int result = jumlah_data[0];
			for (int i = 1; i < jumlah_data.size(); i++) {
				if (dis > abs(jumlah_data[i] - q)) {
					dis = abs(jumlah_data[i] - q);
					result = jumlah_data[i];
				}
			}
			printf("Closest sum to %d is %d.\n", cari, result);
		}
	}

	return 0;
}