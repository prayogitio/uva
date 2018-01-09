#include <cstdio>
#include <cstring>
using namespace std;

int n = 5;
long long memo[5][30001];
int coinValue[] = {1, 5, 10, 25, 50};

long long coinchange(int type, int value) {
	if (type > 4)
		return 0;
	if (value == 0)
		return 1;
	if (value < 0)
		return 0;
	if (memo[type][value] != -1) return memo[type][value];
	return memo[type][value] = coinchange(type+1, value) + coinchange(type, value-coinValue[type]);
}

int main() {
	int set;	
	memset(memo, -1, sizeof(memo));
	while (scanf("%d", &set) != EOF) {		
		long long result = coinchange(0, set);
		if (result > 1)
			printf("There are %lld ways to produce %d cents change.\n", result, set);
		else
			printf("There is only %lld way to produce %d cents change.\n", result, set); 
	}
	return 0;
}