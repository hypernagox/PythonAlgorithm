#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<pi> adj[201];
struct Data
{
	int cost;
	int cur;
	int first = -1;
	const auto operator<(const Data& d)const {
		return cost > d.cost;
	}
};
int bestDists[201];
int memo[201][201];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b, c; cin >> a >> b >> c;
		adj[a].emplace_back(c, b);
		adj[b].emplace_back(c, a);
	}
	for (int i = 1; i <= n; ++i)
	{
		priority_queue<Data> pq;
		pq.emplace(0, i, -1);
		fill(bestDists, bestDists + n + 1, 987654321);
		bestDists[i] = 0;
		while (!pq.empty())
		{
			auto [cost, cur, first] = pq.top();
			pq.pop();
			if (bestDists[cur] < cost)continue;
			if (first != -1)
			{
				memo[i][cur] = first;
				//cout << first << endl;
			}
			for (const auto [c, next] : adj[cur])
			{
				const auto new_cost = c + cost;
				if (bestDists[next] > new_cost)
				{
					//if (first == -1)first = next;
					bestDists[next] = new_cost;
					pq.emplace(new_cost, next, (-1==first ? next:first));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)cout << '-';
			else cout << memo[i][j];
			cout << ' ';
		}
		cout << '\n';
	}
}