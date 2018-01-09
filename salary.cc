#include <cstdio>
#include <algorithm>
using namespace std;
void sort();
int decide(int a, int b,int c) {
	int data[3] = {a,b,c};
	sort(data, data + 3);
	return data[1];
}

int main() {
	int t,num1,num2,num3;
	scanf("%d",&t);
	for (int b = 1; b <= t;b++){
		scanf("%d %d %d",&num1, &num2, &num3);
		int x = decide(num1,num2,num3);
		printf("Case %d: %d\n",b,x);	
	}
		
	return 0;
}