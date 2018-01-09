#include <cstdio>
using namespace std;


int main() {
	int n;
	long long target;
	while (scanf("%d %lld", &n,&target) != EOF) {
		int x=n/2;
		int y=n/2;
		long long value = 2;
		int counter=0;
		bool found=false;
		if (target == 1) {
			printf("Line = %d, column = %d.\n",x+1,y+1);
		} else {
			for (int i=1;i<=n;i++) {
				if (i == n) {
					counter=1;
					while (counter <= i && found==false) {//go bottom
						x=x+1;
						if (value == target) {
							found = true;
							counter=i+1;
						} else {		
							++value;
							counter++;	
						}
					}
					counter=1;
					while (counter <= i && found==false) {//go right
						y=y+1;
						if (value == target) {
							found = true;
							counter=i+1;
						} else {		
							++value;
							counter++;	
						}
					}
					counter=1;
					while (counter <= i && found==false) {//go top
						x = x-1;
						if (value == target) {
							found = true;
							counter=i+1;
						} else {		
							++value;
							counter++;	
						}
					}
				} else if (i % 2 != 1) {
					counter=1;
					while (counter <= i && found==false) {//go top
						x = x-1;
						if (value == target) {
							found = true;
							counter=i+1;
						} else {		
							++value;
							counter++;	
						}
					}
					counter=1;
					while (counter <= i && found==false) {//then go left
						y = y-1;
						if (value == target) {
							found = true;
							counter=i+1;
						} else {		
							++value;
							counter++;	
						}
					}			
				} else {
					counter=1;
					while (counter <= i && found==false) {//go bottom
						x=x+1;
						if (value == target) {
							found = true;
							counter=i+1;
						} else {		
							++value;
							counter++;	
						}
					}
					counter=1;
					while (counter <= i && found==false) {//go right
						y=y+1;
						if (value == target) {
							found = true;
							counter=i+1;
						} else {		
							++value;
							counter++;	
						}
					}
				} 	
			}
			if (n!=0) {
				y = n - 1 - y;
				printf("Line = %d, column = %d.\n",x+1,y+1);	
			}
			
			/*if (n!=0) {
				for (int i=0;i<n;i++) { //reverse row
				    for (int j=0;j<n/2;j++) {
				        swap(data[i][j],data[i][n-1-j]);
				    }
				}
				for (int i=0;i<n;i++) {
					for (int j=0;j<n;j++) {
						if (data[i][j] == target) {
							row = i+1;
							col = j+1;
							j=n;
							i=n;
						}
					}
				}	
			}	*/
		}
	}
	return 0;
}