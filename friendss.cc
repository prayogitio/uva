#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010

vector<int>adj[30000+2];
bool vis[30000+2];
int cnt;

void dfs(int u)
{
    vis[u]=true;
    cnt++;
    int ul=adj[u].size();
    for(int i=0;i<ul;i++)
    {
        int v=adj[u][i];
        if(!vis[v]) dfs(v);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int kk=1, tc, n, m, u, v;
    string s;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mx=0;
        CLR(vis);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                cnt=0;
                dfs(i);
                mx=max(mx, cnt);
                //cout<<cnt<<endl;
            }
        }
        //cout<<"Case "<<kk++<<": "<< <<"\n";
        cout << mx << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }

    return 0;
}