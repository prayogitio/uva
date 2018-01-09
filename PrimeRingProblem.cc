#include <cstdio>
#include <cstring>
using namespace std;

int n;
int res[20];
bool visited[20];

bool isPrime(int s) {
	for (int j = 2; j < s; j++) {
		if (s % j == 0) return false;
	}
	return true;
}

void search(int x) {
	if (x == n-1 && isPrime(res[n] + res[n-1])) {
		printf("%d", res[0]);
		for (int m = 1; m < n; m++) {
			printf(" %d", res[m]);
		}
		printf("\n");
	}
	for (int i = 2; i <= n; i++) {
		if (!visited[i] && isPrime(res[x] + i)) {
			res[x+1] = i;
			visited[i] = true;			 
			search(x+1);
			visited[i] = false;
		}
	}
}

int main() {
	int cases = 1;
	while (scanf("%d", &n) != EOF) {
		printf("Case %d:\n", cases++);
		res[0] = 1;
		res[n] = 1;
		search(0);
		if (cases > 1) printf("\n");
	}
}