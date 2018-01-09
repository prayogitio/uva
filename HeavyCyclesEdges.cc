#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class UnionFind {
	private : vector<int> p, rank;
	public : 
		UnionFind(int N) {
			p.assign(N, 0);
			rank.assign(N, 0);
			for (int i = 0; i < N; i++) p[i] = i;
		}
		int findSet(int i) {
			return (p[i] == i) ? i : (p[i]=findSet(p[i]));
		}
		int isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i);
				int y = findSet(j);
				if (rank[x] > rank[y]) {
					p[y] = x;
				} else {
					p[x] = y;
					if (rank[x] == rank[y])
						rank[y]++;
				}
			}
		}
};

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) && n) {
		vector<pair<int,pair<int,int>>> EdgeList;
		vector<int> WeightList;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back({w,{u,v}});
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind uf(n);
		for (int i = 0; i < EdgeList.size(); i++) {
			pair<int, pair<int,int>> front = EdgeList[i];
			if (!uf.isSameSet(front.second.first, front.second.second)) {
				uf.unionSet(front.second.first, front.second.second);
			} else {
				WeightList.push_back(front.first);
			}
		}
		if (WeightList.size() == 0) {
			printf("forest\n");
		} else {
			for (int i = 0; i < WeightList.size(); i++) {
				if (i == 0) {
					printf("%d", WeightList[i]);
				} else printf(" %d", WeightList[i]);
			}
			printf("\n");	
		}
	}
	return 0;
}