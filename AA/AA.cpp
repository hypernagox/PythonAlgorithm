#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> build[501];
int cost[501];
int res[501];
int inDegree[501];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
		res[i] = cost[i];
		for (;;) {
			int x; cin >> x;
			if (-1 == x)break;
			build[x].emplace_back(i);
			++inDegree[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (0 == inDegree[i])q.emplace(i);
	}
	while (!q.empty()) {
		const int n = q.front(); q.pop();
		for (auto i : build[n]) {
			res[i] = max(res[i], res[n] + cost[i]);
			if (0 == --inDegree[i]) {
				q.emplace(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i)cout <<  res[i] << '\n';
}
