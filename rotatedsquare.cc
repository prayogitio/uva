#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void ReverseRow(char square[100][100], int x) {
	for (int i=0;i<x;i++) { //reverse row
	    for (int j=0;j<x/2;j++) {
	        swap(square[i][j],square[i][x-1-j]);
	    }
	}
	return;
}

void ReverseColumn(char square[100][100], int x) {
	for (int i=0;i<x;i++) { //reverse column
	    for (int j=0;j<x/2;j++) {
	        swap(square[j][i],square[x-1-j][i]);
	    }
	}
	return;
}

void Transpose(char square[100][100], int x) {
	for (int i=0;i<x;i++) {
	    for (int j=i+1;j<x;j++) {
	        swap(square[i][j],square[j][i]);
	    }
	}
	return;
}

void Cetak(char square[100][100],int x) {
	for (int i=0;i<x;i++) {
	    for (int j=0;j<x;j++) {
	        printf("%c",square[i][j]);
	    }
	    printf("\n");
	}
}

int hasil(char big_square[100][100],char square[100][100],int x, int m) {
	int sum=0;
	int total=0;
	for (int i=0;i<=x-m;i++) {
		for (int j=0;j<=x-m;j++) {
			sum=0;
			for (int x=0;x<m;x++) {
				for (int y=0;y<m;y++) {
					if (big_square[i+x][j+y] == square[x][y]) {
						sum++;
						if (sum == m*m) {
							total++;
						}
					}
				}
			}
		}
	}
	return total;
}

int main() {
	int n,m;
	char fill[100];
	char big_square[100][100];
	char init_square[100][100];
	char init_square1[100][100];
	char small_square[100][100];
	while (scanf("%d %d", &n,&m) != EOF){
		for (int i=0;i<n;i++) {
			scanf("%s",fill);
			for (int j=0;j<n;j++) {
				big_square[i][j] = fill[j];
			}
		}
		for (int i=0;i<m;i++) {
			scanf("%s",fill);
			for (int j=0;j<m;j++) {
				small_square[i][j] = fill[j];
				init_square[i][j] = fill[j];
				init_square1[i][j] = fill[j];
			}
		}
		if (m == 1){
			int num=0;
			for (int i=0;i<n;i++) {
				for (int j=0;j<n;j++) {
					if (big_square[i][j] == small_square[0][0]) {
						num++;
					}
				}
			}
			printf("%d %d %d %d\n", num,num,num,num);
		} else {
			int hasil1 = hasil(big_square,small_square,n,m);
			Transpose(small_square,m);
			ReverseRow(small_square,m);
			int hasil2 = hasil(big_square,small_square,n,m);
			ReverseRow(init_square,m);
			ReverseColumn(init_square,m);
			int hasil3 = hasil(big_square,init_square,n,m);
			ReverseRow(init_square1,m);
			Transpose(init_square1,m);
			int hasil4 = hasil(big_square,init_square1,n,m);
			if (n != 0){
				printf("%d %d %d %d\n",hasil1,hasil2,hasil3,hasil4);	
			}	
		}
	}
	return 0;
}