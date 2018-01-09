#include<algorithm>
#include<cstdio>
#include<iostream>
 
using namespace std;
 
int T, N, H;
string s;
 
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &H);
        s = "";
        for(int i = 0; i < N; i++) {
            if(i < N - H)
                s += "0";
            else
                s += "1";
        }
        do {
            cout << s << endl;
        } while(next_permutation(s.begin(), s.end()));
 
        if(T) printf("\n");
    }
}