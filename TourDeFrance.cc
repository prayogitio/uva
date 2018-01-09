#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int f, r;
	while (scanf("%d %d", &f, &r) != EOF) {
		if (f == 0) break;
		vector<double> front;
		vector<double> rear;
		for (int i = 0; i < f; i++) {
			double d;
			scanf("%lf", &d);
			front.push_back(d);
		}
		for (int i = 0; i < r; i++) {
			double l;
			scanf("%lf", &l);
			rear.push_back(l);
		}
		double s[100];
		int k = 0;
		for (int i = 0; i < front.size(); i++) {
			for (int j = 0; j < rear.size(); j++) {
				double x = front[i] / rear[j];
				s[k] = x;
				k++;
			}
		}
		sort(s, s + k);
		double maxS = -1;
		for (int i = 0; i < k-1; i++) {
			maxS = max(maxS,s[i + 1] / s[i]);
		}
		printf("%0.2lf\n", maxS);
	}
	return 0;
}