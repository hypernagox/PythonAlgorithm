#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> adj[10001];
vector<pair<int, int>> adj2[10001];
int inDegree[10001];
queue<int> q;
int res[10001];
int cnt;
int u, v;
bool visited[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int M = m;
	while (M--) {
		int x, y, z; cin >> x >> y >> z;
		adj[x].emplace_back(y, z);
		adj2[y].emplace_back(x, z);
		++inDegree[y];
	}
	for (int i = 1; i <= n; ++i) {
		if (0 == inDegree[i])q.emplace(i);
	}
	while (!q.empty()) {
		const int node = q.front(); q.pop();
		for (const auto [n, val] : adj[node]) {
			if (0 == --inDegree[n])q.emplace(n);
			res[n] = max(res[n], res[node] + val);
		}
	}
	cin >> u >> v;
	cout << res[v] << '\n';
	q.emplace(v);
	while (!q.empty()) {
		const auto n = q.front(); q.pop();
		visited[n] = true;
		for (auto i : adj2[n]) {
			if (res[i.first] == res[n] - i.second) {
				++cnt;
				if(!visited[i.first])
					q.emplace(i.first);
			}
		}
	}
	cout << cnt;
}
