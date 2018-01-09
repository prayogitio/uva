#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int arr[3000];
int temp[3000];

int count_jolly(int arr[],int n){
	int jolly=1;
	for (int i=0;i<n;i++){
		int dif = abs(arr[i+1]-arr[i]);
		temp[i] = dif;
	}
	sort(temp, temp+(n-1));
	for (int j=0;j<n-1;j++){
		if(j+1 == temp[j]){
			jolly = 1;
		}else {
			jolly = 0;
			break;	
		}
	}
	return jolly;
}

int main() {
	int n=0;
	while (scanf("%d ", &n) != EOF){
		for (int i=0;i<n;i++){
			scanf("%d ", &arr[i]);
		}
		int result = count_jolly(arr,n);
		if (result == 1){
			printf("Jolly\n");
		}
		else if (result == 0){
			printf("Not jolly\n");
		}
	}

	return 0;
}