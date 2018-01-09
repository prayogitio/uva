#include <cstdio>
#include <math.h>
using namespace std;

int main() {
	long long n;
	long long find;
	while (scanf("%lld %lld",&n,&find) != EOF) {
		int row=0;
		int col=0;
		int i=0;
		bool sama=false;
		long long temp;
		long long max = n*n;
		double prox = sqrt(find);
		long long proxi = floor(prox);
		if (n != 0 && find !=0) {
			if (proxi % 2 == 0) {
				proxi--;
			}
			if (find == proxi*proxi) {
				proxi = proxi-2;
			}
			if (find == 1) {
				printf("Line = %lld, column = %lld.\n",n/2+1,n/2+1);
			}
			if (find > proxi*proxi) {
				temp = proxi+2;
				row = proxi+2;
				col = proxi+1;
				long long proxii = (proxi*proxi)+1;//25
				while (proxii != find && col > 1) {
					proxii++;
					col--;
				}
				while (proxii != find && row > 1) {
					proxii++;
					row--;
				}
				while (proxii != find && col < temp) {
					proxii++;
					col++;
				}
				while (proxii != find && row < temp) {
					proxii++;
					row++;
				}
				if (n!=0) {
					int penambah = 0;
					for (int i=temp;i<n;i=i+2) {
						penambah++;
					}
					printf("Line = %d, column = %d.\n",row+penambah,col+penambah);
				}
			}		
		}
	} 
	return 0;
}