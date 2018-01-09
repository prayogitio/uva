#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> adj(101);
int sol;
bool visited[101];

void dfs(int start) {
    for (int j = 0; j < adj[start].size(); j++) {
    	if (!visited[adj[start][j]]) {
    		visited[adj[start][j]] = true;
    		sol++;
    		dfs(adj[start][j]);
    	}
    }
}

int main() {
    int n;
    cin >> n;
    while (n) {
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        int m;
        cin >> m;
        while (m) {
            int a;
            cin >> a;
            while (a) {
                adj[m].push_back(a);
                cin >> a;
            }
            cin >> m;
        }
        int q;
        for (cin >> q; q; q--) {
            int s;
            cin >> s;
            memset(visited, false, sizeof(visited));
            sol = 0;
            dfs(s);
            cout << n - sol;
            for (int i = 1; i <= n; i++)
                if (!visited[i])
                    cout << " " << i;
            cout << endl;
        }
        cin >> n;
    }
    return 0;
}
