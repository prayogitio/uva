#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		int length;
		int m;
		scanf("%d %d", &length, &m);
		length = length * 100;
		queue<int> left;
		queue<int> right;
		for (int i = 0; i < m; i++) {
			string pos;
			int car;
			scanf("%d", &car);
			cin >> pos;
			if (pos == "left") {
				left.push(car);
			} else {
				right.push(car);
			}
		}
		int ans = 0;
		int capacity = 0;
		int turn = 0;
		while (!(left.empty() && right.empty())) {
			capacity = 0;
			if (turn % 2 == 0) {
				while (!left.empty() && left.front() + capacity <= length) {
					capacity = capacity + left.front();
					left.pop();
				}				
				++ans;
				turn++;
			} else {
				while (!right.empty() && right.front() + capacity <= length) {
					capacity = capacity + right.front();
					right.pop();
				}
				++ans;
				turn++;
			}

		}
		cout << ans << endl;
		
	}

	return 0;
}