#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

stack <int> P;
queue <int> C[105];

int t,n,s,q;
int ax,ay,p,g,r,est;


int main(){

    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d",&n,&s,&q);
        for(int i=0;i<n;i++){
            scanf("%d",&ax);
            while(ax--){
                scanf("%d",&ay);
                C[i].push(ay);
                g++;
            }
        }

        est=r=p=0;

        while(g>0){
            if(est){
                r+=2;
            }
            est=1;
            while(  (!P.empty()&&C[p].size()<q) || (!P.empty() &&P.top()==p+1)   ){
                if(P.top()==p+1){
                    P.pop();
                    g--;
                }
                else {
                    C[p].push(P.top());
                    P.pop();
                }
                r++;
            }

            while(P.size()<s && !C[p].empty()){
                P.push(C[p].front());
                C[p].pop();
                r++;
            }

            p++;
            p%=n;


        }

        printf("%d\n",r);

    }

    return 0;

}