#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n;
	scanf("%d\n", &n);
	string kata;
	double count=0;
	map<string,double> temp;
	for (int x = 0; x < n; x++) {
		while (getline(cin,kata) && !kata.empty()) {
			temp[kata] = ++temp[kata];
			count++;
		}
		map<string,double>::iterator it;
		for(it = temp.begin(); it != temp.end() ; it++)
		{
			cout << it->first;
			double result = (it->second / count) * 100;
			printf(" %0.4lf\n", result);
		}
		if (x < n-1) {
			printf("\n");
		}
		temp.clear();
		count = 0;
	}
	
	return 0;
}