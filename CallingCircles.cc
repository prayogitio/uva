#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> EdgeList;
vector<vector<int>> ReverseEdgeList;
int visited[26];
map<string,int> nametonum;
map<int,string> numtoname;
stack<int> s;
vector<int> result;

void dfs(int u) {
	if (visited[u]) return;
	visited[u] = 1;
	for (int j = 0; j < EdgeList[u].size(); j++) {
		int v = EdgeList[u][j];
		dfs(v);
	}
	s.push(u);
}

void dfss(int u) {
	if (visited[u]) return;
	visited[u] = 1;
	result.push_back(u);
	for (int j = 0; j < ReverseEdgeList[u].size(); j++) {
		int v = ReverseEdgeList[u][j];
		dfss(v);
	}
}

int main() {
	int n, m;
	int z = 1;
	bool first = true;
	while (scanf("%d %d", &n, &m) && n && m) {
		if (first == false) printf("\n");
		first = false;
		int setMax = max(n,m);
		printf("Calling circles for data set %d:\n",z++);
		memset(visited, 0, sizeof(visited));
		EdgeList.clear();
		ReverseEdgeList.clear();
		EdgeList.resize(setMax);
		ReverseEdgeList.resize(setMax);
		nametonum.clear();
		numtoname.clear();
		int x = 0;
		int M = m;
		while (M--) {
			string a,b; cin >> a; cin >> b;
			if (nametonum.count(a) == 0) {
				nametonum[a] = x;
				numtoname[x] = a;
				x++;
			}
			if (nametonum.count(b) == 0) {
				nametonum[b] = x;
				numtoname[x] = b;
				x++;
			}
			EdgeList[nametonum[a]].push_back(nametonum[b]);
			ReverseEdgeList[nametonum[b]].push_back(nametonum[a]);
		}
		for (int i = 0; i < n; i++) {
			dfs(i);
		}
		memset(visited, 0, sizeof(visited));
		int total_person = n;
		while (!s.empty()) {
			dfss(s.top());
			sort(result.begin(), result.end());
			n = n - result.size();
			for (int g = 0; g < result.size(); g++) {
				if (result.size() > 0) {
					if (g == 0) 
						cout << numtoname[result[g]];
					else cout << ", "<<numtoname[result[g]];
				} else
				cout << numtoname[result[g]];					
			}
			if (result.size() > 0 && n != 0) printf("\n");
			result.clear();
			s.pop();
		}
		printf("\n");
	}
	return 0;
}