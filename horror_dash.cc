#include <cstdio>
#include <algorithm>
using namespace std;
 
int data[100];

int get_max(int d[]){
	sort(d, d + 100);
	return d[99];
}

int main() {
	int t = 0;
	scanf("%d",&t);
	int c = 0;
	while (c < t){
		int n=0;
		scanf("%d ", &n);
		for (int i=0;i<n;i++){
			scanf("%d", &data[i]);
		}	

		int result = get_max(data);
		printf("Case %d: %d\n",c+1, result);
	
		for (int x=0;x<100;x++){
			data[x]=0;
		}
	c++;
	}

	return 0;
}