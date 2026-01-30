#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int MAX_VAL = 987654321;
ull dists[3][100001];
bool visited[3][100001];
vector<pll> adj[100001];
int friends[3];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n;
	for (auto& i : friends)cin >> i;
	cin >> m;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].emplace_back(z, y);
		adj[y].emplace_back(z, x);
	}
	for (int i = 0; i < 3; ++i)
	{
		priority_queue<pll,vector<pll>,greater<pll>> pq;
		dists[i][friends[i]] = 0;
		pq.emplace(0, friends[i]);
		fill(dists[i], dists[i] + n + 1, MAX_VAL);
		while (!pq.empty())
		{
			const auto [c, cur] = pq.top();
			pq.pop();
			if (visited[i][cur])continue;
			visited[i][cur] = 1;
			//if (dists[i][cur] < c)continue;
			for (const auto [cost, next] : adj[cur])
			{
				const auto new_cost = c + cost;
				if (dists[i][next] > new_cost)
				{
					dists[i][next] = new_cost;
					pq.emplace(new_cost, next);
				}
			}
		}
	}
	ll res_dist = 0;
	ll res = 0;
	for (int i = 1; i <= n; ++i)
	{
		const auto v = min({ dists[0][i], dists[1][i], dists[2][i] });
		if (res_dist < v)
		{
			res_dist = v;
			res = i;
		}
	}
	cout << res;
}