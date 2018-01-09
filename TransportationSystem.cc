#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
	private : vector<int> p, rank;
	public :
		UnionFind(int N) {
			p.assign(N, 0);
			rank.assign(N, 0);
			for (int i = 0; i < N; i++)
				p[i] = i;
		}
		int findSet(int i) {
			return (p[i]==i) ? i : (p[i] = findSet(p[i]));
		}
		int isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j) {
			if (!isSameSet(i,j)) {
				int x = findSet(i);
				int y = findSet(j);
				if (rank[x] > rank[y]) {
					p[y] = x;
				} else {
					p[x] = y;
					if (rank[x] == rank[y]) {
						rank[y]++;
					}
				}
			}
		}
};

int main() {
	int T; scanf("%d", &T);
	int h = 1;
	while (T--) {
		int n, r; scanf("%d %d", &n, &r);
		vector<pair<int,int>> c(n);
		vector<pair<double,pair<int,int>>> EdgeList;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &c[i].first, &c[i].second);
			for (int j = 0; j < i; j++) {
				double dist = sqrt(pow(c[i].first-c[j].first, 2) + pow(c[i].second-c[j].second, 2));
				EdgeList.push_back({dist,{i,j}});
			}
		}
		sort(EdgeList.begin(), EdgeList.end());
		int s = EdgeList.size();
		double rail = 0, road = 0;
		int num_state = n;
		UnionFind u(n);
		for (int j = 0; j < s; j++) {
			pair<double, pair<int,int>> front = EdgeList[j];
			if(!u.isSameSet(front.second.first, front.second.second)) {
				if (front.first <= r) {
					road += front.first;
					num_state--;
				} else {
					rail += front.first;
				}
				u.unionSet(front.second.first, front.second.second);
			}
		}
		printf("Case #%d: %0.lf %0.lf %0.lf\n", h++, round(num_state), round(road), round(rail));
	}
	return 0;
}