#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<int,int> visited;
map<int,vector<int>> G;
vector<int> result;

void dfs(int u) {
	if (visited[u]) return;
	visited[u] = 1;
	result.push_back(u);
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		dfs(v);
	}
}

int main() {
	int n;
	int mx;
	scanf("%d", &n);
	while (n--) {
		vector<int> data;
		G.clear();
		visited.clear();
		int N, M;
		scanf("%d %d", &N, &M);
		while (M--) {		
			int a,b;
			scanf("%d %d", &a,&b);
				if (data.size() > 0) {
				sort(data.begin(), data.end());
				int awal = 0;
				int akhir = data.size();
				bool sudah = false;
				while (awal != akhir) {
					int mid = awal + akhir /2;
					if (data[mid] = a) {
						data.push_back(a);
						data.push_back(b);
						sudah = true;
						awal = akhir;					
					}
					if (data[mid] < a) {
						awal = mid + 1;
					}
					if (data[mid] > a) {
						akhir = mid - 1;
					}
				}
				awal = 0;
				akhir = data.size();
				while (awal != akhir && sudah == false) {
					int mid = awal + akhir /2;
					if (data[mid] = b) {
						data.push_back(a);
						data.push_back(b);
						sudah = true;					
					}
					if (data[mid] < b) {
						awal = mid + 1;
					}
					if (data[mid] > b) {
						akhir = mid - 1;
					}
				}
			} else {
				data.push_back(a);
				data.push_back(b);
			} 			
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(data[0]);
		cout << result.size() << endl;
		result.resize(0);
	}

	return 0;
}