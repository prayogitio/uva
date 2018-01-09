#include <cstdio>
#include <string>
using namespace std;

char define_operator(int a, int b){
	char result;
	if (a == b){
		result = '='; 
	}
	else if (a < b){
		result = '<';
	}
	else if (a > b){
		result = '>';
	}
	return result;
}

int main() {
	int t;
	int num1,num2;
	char res;
	scanf("%d",&t);
	if (t < 15){
		for (int i=1;i<=t;i++){
		scanf("%d %d", &num1, &num2);
		res = define_operator(num1,num2);
		printf("%c\n", res);
		}	
	}

	return 0;
}