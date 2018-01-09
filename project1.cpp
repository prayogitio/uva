#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

void formula();

void formula(){

	int i;
	int j;
	int n,o,c,i_c;
	while (scanf("%d %d",&i,&j)!=EOF){
		int num = 0;
		while (num <= i_c){
			int max = 0;
				for (o = i[num]; o <= j[num]; o++){
					c=1;
					n = o;
					while (n != 1){
						if (n % 2 == 0){
							n = n/2;
						}
						else {
							n = (3*n) + 1;
						}
						c++;
					}
					if (c > max){
					max = c;
					}
				}	
			printf("%d %d %d\n", i[num],j[num],max);
			num++;
		}
	
	}
	
		
}

int main(){
	formula();
	return 0;
}