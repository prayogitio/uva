#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<vector<int>> adj(101);
int sol;
bool visited[101];

void dfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = false;
    while(!q.empty()) {
        int top = q.front();
        for(int i = 0; i < adj[top].size(); i++) {
           int n = adj[top][i]; 
           if(visited[n]) continue;
           visited[n] = 1;
           sol++;
           q.push(n);
        }
        q.pop();
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
