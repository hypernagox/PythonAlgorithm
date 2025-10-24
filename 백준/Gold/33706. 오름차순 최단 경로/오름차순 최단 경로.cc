#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> adj[200001];
bool visited[200001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	queue<int> q;
	q.emplace(1);
	visited[1] = true;
	while (!q.empty())
	{
		const auto cur = q.front(); q.pop();
		for (const auto next : adj[cur])
		{
			if (visited[next])continue;
			if (cur > next)
			{
				continue;
			}
			visited[next] = true;
			q.emplace(next);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}