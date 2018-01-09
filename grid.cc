#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d\n", &n);
	int data;
	
	for (int x = 0 ; x < n ; x++) {
		vector<vector<int>> v;
		vector<vector<int>> temp;
		int count=0;
		for (int i = 0 ; i < 3 ; i++) {
			vector<int> w;
			for (int j = 0 ; j < 3 ; j++) {
				scanf("%1d",&data);
				w.push_back(data);
				if (data == 0) {
					count++;
				}
			}
			v.push_back(w);
			temp.push_back(w);
		}
		if (count == 9) {
			printf("-1\n");
		} else {
			int fungsi = 0;
			int kosong = 0;
			while (1) {
				kosong=0;
				for (int i = 0 ; i < 3 ; i++) {
					for (int j = 0 ; j < 3 ; j++) {
						if (i == 0 && j == 0) {
							temp[i][j] = (v[i][j+1] + v[i+1][j])%2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 1 && j == 0) {
							temp[i][j] = (v[i-1][j] + v[i][j+1] + v[i+1][j]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 2 && j == 0) {
							temp[i][j] = (v[i-1][j] + v[i][j+1]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 0 && j == 1) {
							temp[i][j] = (v[i][j-1] + v[i+1][j] + v[i][j+1]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 1 && j == 1) {
							temp[i][j] = (v[i-1][j] + v[i][j-1] + v[i][j+1] + v[i+1][j]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 2 && j == 1) {
							temp[i][j] = (v[i][j-1] + v[i-1][j] + v[i][j+1]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 0 && j == 2) {
							temp[i][j] = (v[i][j-1] + v[i+1][j]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 1 && j == 2) {
							temp[i][j] = (v[i-1][j] + v[i][j-1] + v[i+1][j]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
						if (i == 2 && j == 2) {
							temp[i][j] = (v[i-1][j] + v[i][j-1]) % 2;
							if (temp[i][j] == 0) {
								kosong++;
							}
						}
					}
				}
				v=temp;
				fungsi++;
				if (kosong==9) break;
			}
			printf("%d\n", fungsi-1);
		}
		

	}	

	return 0;
}