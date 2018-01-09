#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    string s;

    while(t--) {
        vector<int>a;
        int n;
        cin>>n;
        for(int i=0;i<=n;i++) {
            int x;cin>>x;
            a.push_back(x);
        }
        int d,k;
        cin >> d >> k;
        int c = 1;
        int total = 0;
        while(total < k)
            total+=d*c++;

        long long ats = 0;
        for(int i=0; i<a.size();i++)
                ats+=a[i] * pow(c-1,i);
        cout<<ats<<"\n";
    }
}
