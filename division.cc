#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <string>
using namespace std;

void find_region(int a,int b) {
	if (a == 0 || b == 0){
		printf("divisa\n");
	}else if (a > 0 && b > 0){
		printf("NE\n");
	}else if (a > 0 && b < 0){
		printf("SE\n");
	}else if (a < 0 && b > 0){
		printf("NO\n");
	}else if (a < 0 && b < 0){
		printf("SO\n");
	}
}

int set_x(int x){
	int nilai;
	if (x < 0){
		nilai = abs(x);
	}
	else if(x > 0){
		nilai = -x;
	}else if (x == 0){
		nilai = 0;
	}
	return nilai;
}
int set_y(int y){
	int nilai;
	if (y < 0){
		nilai = abs(y);
	}
	else if(y > 0){
		nilai = -y;
	}else if (y == 0){
		nilai = 0;
	}
	return nilai;
}
int main() {
	int n=1;
	int div_x, div_y;
	int pos_x, pos_y;
	int penambah_x, penambah_y;
	
	while (n != 0){
	scanf("%d", &n);
	scanf("%d %d", &div_x, &div_y);
	penambah_x = set_x(div_x);
	penambah_y = set_y(div_y);
		for (int t = 1; t <= n; t++){
			scanf("%d %d", &pos_x, &pos_y);
			pos_x = pos_x + penambah_x;
			pos_y = pos_y + penambah_y;
			find_region(pos_x,pos_y);
		}	
	}	
	
	
	return 0;
}
