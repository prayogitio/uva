#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

char letter[100];
double letter_value[100];
char article[10000];
char temp[100];
int main() {
	int n=0;
	int m=0;
	int article_line=0;
	double price;
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		scanf("%d",&m);
		for (int j=0;j<=m;j++){	
			gets(temp);
			sscanf(temp,"%c %lf",&letter[j],&letter_value[j]);
		}

		scanf("%d", &article_line);
		price=0;
		for (int x=0;x<=article_line;x++){
			gets(article);
			for (int y=0;y<=(unsigned)strlen(article);y++){
				for (int z=1;z<=m;z++){
					if (article[y] == letter[z]){
						price = price + letter_value[z];						
					}else{
						price = price + 0;
					}
				}
			}
		}
	double total = price/100;
	printf("%.2lf$\n", total);
	}
	return 0;
}