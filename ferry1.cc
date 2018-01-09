#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		int time;
		char pos[10];
		queue<int> left;
		queue<int> right;
		for (int j = 0; j < m; j++) {
			scanf("%d %s", &time, pos);
			if (strcmp(pos,"left") == 0) {
				left.push(time);
			}
			if (strcmp(pos,"right") == 0) {
				right.push(time);
			}
		}
		int timer = min(left.front(), right.front());
		queue<int> ship;
		if (left.front() < right.front()) {
			while (1) {
				while (left.size() > 0) {
					if (left.front() <= timer && ship.size() < n) {
						ship.push(left.front());
						left.pop();
					}
					if (left.front() > timer || ship.size() == n) { 
						timer = timer + t;				
						while (ship.size() > 0) {
							printf("%d\n", timer);
							ship.pop();
						}
						break;	
					}
				}
				while (right.size() > 0) {
					if (right.front() == timer && ship.size() < n) {
						ship.push(right.front());
						right.pop();
					}
					if (right.front() != timer || ship.size() == 0) {
						timer = timer + t;
						while (ship.size() > 0) {
							printf("%d\n", timer);
							ship.pop();
						}
						break;
					}
				}
				if (left.size() == 0 && right.size() == 0) {
					break;
				}
			}
			printf("\n");			
		} else {
			while (1) {
				while (right.size() > 0) {
					if (right.front() == timer && ship.size() < n) {
						ship.push(right.front());
						right.pop();
					}
					if (right.front() != timer || ship.size() == 0) {
						timer = timer + t + t;
						while (ship.size() > 0) {
							printf("%d\n", timer);
							ship.pop();
						}
						break;
					}
				}
				while (left.size() > 0) {
					if (left.front() <= timer && ship.size() < n) {
						ship.push(left.front());
						left.pop();
					}
					if (left.front() != timer || ship.size() == n) { 
						timer = timer + t;				
						while (ship.size() > 0) {
							printf("%d\n", timer);
							ship.pop();
						}
						break;	
					}
				}
				if (right.size() == 0) {
					timer = timer + t;
				}
				if (left.size() == 0) {
					timer = timer + t;
				}
				if (left.size() == 0 && right.size() == 0) {
					break;
				}
			}
			printf("\n");
		}

	}

	return 0;
}