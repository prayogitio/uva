#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj(100);
vector<int> visited(100,0);

void bfs(int start, int tot) {
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()) {
        int top = q.front();
        for(int i = 0; i < adj[top].size(); i++) {
           int n = adj[top][i]; 
           if(visited[n]) continue;
           visited[n] = 1;
           q.push(n);
        }
        q.pop();
    }
    vector<int> result;
    for (int i = 0; i < tot; i++) {
    	if (!visited[i]) {
    		result.push_back(i+1);
    	}
    }
    printf("%d", result.size());
    for (int i = 0; i < result.size(); i++)
    printf(" %d", result[i]);
}

int main() {
	int tot;
	while (scanf("%d", &tot) && tot) {
		int u = 0,v = 200;
		while (scanf("%d", &u) && u) {
			while (scanf("%d", &v) && v) {
				adj[u-1].push_back(v-1);
			}
		}
		int c, node;
		scanf("%d", &c);
		for (int i = 0; i < c; i++) {
			scanf("%d", &node);
			if (v == 200) {
				printf("%d", tot);
				for (int i = 0; i < tot; i++) {
					printf(" %d", i+1);
				}
				printf("\n");
				break;
			} else {
				bfs(node-1, tot);
				fill(visited.begin(), visited.end(), 0);	
			}
			printf("\n");
		}				
	}
	
	return 0;
}