#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> adj[21];
bool visited[21];
int ans = 0;
void GO(const int cur,const int cnt)
{
	if (cur > n)
	{
		ans = max(ans, cnt);
		return;
	}
	if (visited[cur])
	{
		GO(cur + 1, cnt);
		return;
	}
	visited[cur] = true;
	for (const auto next : adj[cur])
	{
		if (visited[next])continue;
		visited[next] = true;
		GO(cur + 1, cnt + 2);
		visited[next] = false;
	}
	visited[cur] = false;
	GO(cur + 1, cnt);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	GO(1, 0);
	if (ans < n)++ans;
	cout << ans;
}