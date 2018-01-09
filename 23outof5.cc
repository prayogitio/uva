#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int set[5];

bool search(int n, long y) {
	if (n == 5) {
		if (y == 23) {
			return true;
		}
		else return false;
	}
	return search(n+1, y + set[n]) || search(n+1, y - set[n]) || search(n+1, y * set[n]);
}

int main() {
	int a,b,c,d,e;
	while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) && a && b && c && d && e) {
		set[0] = a; set[1] = b; set[2] = c; set[3] = d; set[4] = e;
		bool possible = false;
		sort(set, set+5);
		do {
			if(search(1, set[0])) {
				possible = true;
				break;
			}
		}
		while (next_permutation(set, set+5));
		if (possible) printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
}