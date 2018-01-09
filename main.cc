#include <cstdio>
#include <algorithm>
using namespace std;

int number_cycle(int n){
	int count = 0;
	while (n != 1){
		if (n % 2 == 0){
			n = n/2;
		}
		else{
			n = 3 * n + 1;
		}
		count++;
	}
	return count + 1;
}

int main() {
	int i,j;
	while (scanf("%d%d",&i,&j) != EOF){
		int a = i;
		int b = j;
		if (i > j){
			swap(i,j);
		}
		int biggest = 0;
		for (int x = i; x <= j;x++){
			int temp = number_cycle(x);
			if (temp > biggest){
				biggest = temp;
			}
		}
		printf("%d %d %d\n", a, b, biggest);
	}
	return 0;
}