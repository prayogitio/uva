#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

map<pair<int, int>, string> H;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		H.clear();
		int D;
		scanf("%d", &D);
		while (D--) {
			char merk[30];
			int low, high;
			scanf("%s %d %d", merk, &low, &high);
			H[make_pair(low, high)] = merk;
		}
		int Q;
		scanf("%d", &Q);
		while (Q--) {
			int ketemu = 0;
			int price;
			string result;
			scanf("%d", &price);
			for (map<pair<int,int>,string>::iterator it = H.begin(); it != H.end(); ++it ) {
				int l = it->first.first;
				int h = it->first.second;
				if (price >= it->first.first && price <= it->first.second) {
					ketemu++;
					result = it->second;
				}
			}
			if (ketemu < 1 || ketemu > 1) {
				printf("UNDETERMINED\n");
			} else cout << result << endl;
		}
		if(T) printf("\n");
	}

	return 0;
}