#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

map<string,int> kata;
map<int,string> kataa;
vector<int> visited;
vector<int> dist;
vector<int> parent;

void bfs(int w1, int w2, vector<vector<int>> adj) {
	if (w1 == w2) {
		cout << kataa[w1] << " " << kataa[w2] << " " << 0 << endl; 
	} else {
		queue<int> q;
		visited[w1] = true;
		q.push(w1);
		while (!q.empty()) {
			int u = q.front();
			if (u == w2) break;
			q.pop();
			for (int i = 0; i < adj[u].size(); i++) {	
				int v = adj[u][i];
				if (visited[v]) continue;
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					parent[v] = u;
				}
				visited[v] = true;
				q.push(v);	
			}
		}	
		cout << kataa[w1] << " " << kataa[w2] << " " << dist[w2] << endl; 	
	}
}

bool banding(string kata1, string kata2) {
	int diff = 0;
	if (kata1.length() != kata2.length()) return false;
	int panjang = kata1.length(); 
	for (int i = 0; i < panjang; i++) {
		if (kata1[i] != kata2[i]) {
			diff+=1;
		}
	}
	if (diff == 1) {
		return true;
	}
	return false;
}

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		kata.clear();
		kataa.clear();
		int x = 0;
		char w[15];
		while (cin >> w && w[0] != '*') {
			kata[w] = x;
			kataa[x] = w;
			x++;
		}
		vector<vector<int>> adj(210);
		for (map<string,int>::iterator it = kata.begin(); it != kata.end(); it++) {
			for (map<string,int>::iterator it1 = it; it1 != kata.end(); it1++) {
				if (banding(it->first, it1->first)) {
					adj[it->second].push_back(it1->second);	
					adj[it1->second].push_back(it->second);
				}
			}
		}
		string w11, w22;
		string line;
		size_t pos;
		getline(cin,line);
		getline(cin,line);
		while (line != "") {
			visited.resize(210);
			parent.resize(210);
			dist.resize(210);
			fill(visited.begin(), visited.end(), false);
			fill(parent.begin(), parent.end(), 0);
			fill(dist.begin(), dist.end(), -1);
			pos = line.find(" ");
			w11 = line.substr(0,pos);
			w22 = line.substr(pos+1,line.size());
			dist[kata[w11]] = 0;
			bfs(kata[w11], kata[w22], adj);
			if (!getline(cin,line))
				break;
		}
		if (N != 0) printf("\n");
	}
	return 0;
}