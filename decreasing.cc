#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(6);
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	return 0;
}