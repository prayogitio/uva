#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string dict[110];
string digits[] = {"0","1","2","3","4","5","6","7","8","9"};
string rule;
string rules = "0#";
int n;

void search(int v, string s) {
	if (v == rule.size()) {
		cout << s << endl;
		return;
	}
	if (rule[v] == '#') {
		for (int i = 0; i < n; i++) {
			search(v+1, s+dict[i]);
		}
	}
	if (rule[v] == '0') {
		for (int j = 0; j < 10; j++) {
			search(v+1, s+digits[j]);
		}
	}
}

int main() {
	while (scanf("%d", &n)==1) {
		printf("--\n");
		for (int i = 0; i < n; i++)
			cin >> dict[i];
		int r; scanf("%d", &r);
		for (int i = 0; i < r; i++) {
			cin >> rule;
			search(0, "");
		}
	}
	return 0;
}