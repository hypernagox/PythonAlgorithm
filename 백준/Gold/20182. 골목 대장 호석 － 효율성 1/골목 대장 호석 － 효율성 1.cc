#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<pi> adj[100001];
bool visited[100001];
int n, m, a, b, c;
struct Data
{
	int nokori;
	int cur;
	int max_cost;
};
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> a >> b >> c;
	for (int i = 0; i < m; ++i)
	{
		int x, y, z; cin >> x >> y >> z;
		adj[x].emplace_back(z, y);
		adj[y].emplace_back(z, x);
	}
	queue<Data> q;
	q.emplace(c, a, 0);
	visited[a] = 1;
	int res = -1;
	while (!q.empty())
	{
		const auto [nokori, cur, m_cost] = q.front();
		q.pop();
		if (cur == b)
		{
			res = max(res, m_cost);
			continue;
		}
		for (const auto [c, next] : adj[cur])
		{
			if (visited[next])continue;
			if (nokori < c)continue;
			visited[next] = 1;
			q.emplace(nokori - c, next, max(m_cost, c));
		}
	}
	cout << res;
}