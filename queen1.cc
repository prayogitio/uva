#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int path[8];
int row, col;
int counter;

bool valid(int r, int c) {
    for(int j = 0; j < r; j++) {
        if(c == path[j]) return false;
        if(abs(r - j) == abs(c - path[j])) return false;
    }
    return true;
}	

void search(int n) {
	for(int i = 0; i < 8; i++)
        if(valid(n, i)) {
        	path[n] = i;
        	if (n == 7 && path[col] == row) {
        		printf("%2d      %d", ++counter, path[0]+1);
           		for (int m = 1; m < 8; m++) {
           			printf(" %d", path[m]+1);
           		}	
           		printf("\n");
        	} else {
        		search(n+1);	
        	}
        }
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &row, &col);
		memset(path, -1, sizeof(path));
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		counter = 0;
		row--;
		col--;
		path[col] = row;
		search(0);	
		if (T) printf("\n");	
	}
	return 0;
}