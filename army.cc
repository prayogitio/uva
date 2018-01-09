#include <bits/stdc++.h>
using namespace std;

int main() {
	int s = -1,b = -1;
	int left,right;
	int person[100000];
	int data[2];
	bool low = false;
	bool high = true;
	while (s != 0 && b != 0) {
		scanf("%d %d", &s,&b);
		for (int j=0;j<s;j++) {
				person[j] = j+1;
			}
		
		for (int i=0;i<b;i++) {
			low = false;
			high = false;
			scanf("%d %d", &left,&right);
			for (int i=left;i<=right;i++) {
				for (int j=0;j<s;j++) {
					if (person[j] == i) {
						person[j] = -1;
					}
				}
			}
			for (int h=left-1;h>=0 && low==false;h--){
				if (person[h] != -1) {
					data[0] = person[h];
					low = true;
				}
			}
			for (int h=right-1;h<=s && high==false;h++){
				if (person[h] != -1) {
					data[1] = person[h];
					high = true;
				}
			}
			if (low == false && high == false) {
				printf("* *\n");
			} else if (low == true && high == false) {
				printf("%d *\n",data[0]);
			} else if (low == false && high == true) {
				printf("* %d\n", data[1]);
			} else {
				printf("%d %d\n", data[0],data[1]);
			}
		}
		if (s != 0){
			printf("-\n");	
		}
			
	}	
	return 0;
}