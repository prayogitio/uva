#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		int time;
		char pos[10];
		queue<int> left;
		queue<int> right;
		queue<int> ship;
		vector<int> result;
		for (int j = 0; j < m; j++) {
			scanf("%d %s", &time, pos);
			if (strcmp(pos,"left") == 0) {
				left.push(time);

			}
			if (strcmp(pos,"right") == 0) {
				right.push(time);
			}
		}
		int timer;
		if (right.empty()) {
			timer = left.front();
		} else if (left.empty()) {
			timer = right.front();
		} else {
			timer = min(left.front(), right.front());
		}

		if (right.empty()) {
			while (!left.empty()) {
				while (left.front() <= timer && ship.size() < n) {
					ship.push(left.front());
					left.pop();
				}
				timer = timer + t;
				while (!ship.empty()) {
					result.push_back(timer);
					ship.pop();
				}
				timer = timer + t;
			}
		}

		/*if (left.empty()) {
			while (!right.empty()) {
				while (right.front() <= timer && ship.size() <= n) {
					ship.push(right.front());
					right.pop();
				}
				timer = timer + t;
				while (!ship.empty()) {
					result[make_pair(ship.front(),"right")] = timer;
					ship.pop();
				}
				timer = timer + t;
			}
		}*/
		for(int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
		
	}
	return 0;
}