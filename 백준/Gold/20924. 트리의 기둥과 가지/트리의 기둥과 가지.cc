#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int MAX_VAL = 987654321;
vector<pll> tree[200001];
int n;
int root;
bool visited[200001];
ll giga_node;
ll giga_dist;
void GO(const int cur,const ll c)
{
	visited[cur] = true;
	if ((cur == root) && tree[cur].size() >= 2)
	{
		giga_node = cur;
		giga_dist = c;
		//cout << c << endl;
		return;
	}
	if (tree[cur].size() >= 3)
	{
		giga_node = cur;
		giga_dist = c;
		//cout << c << endl;
		return;
	}
	bool flag = true;
	for (const auto [cost, next] : tree[cur])
	{
		if (visited[next])continue;
		flag = false;
		GO(next, c + cost);
	}
	if (flag)
	{
		giga_node = cur;
		giga_dist = c;
		//cout << c << endl;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> root;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].emplace_back(c, b);
		tree[b].emplace_back(c, a);
	}
	GO(root, 0);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	visited[giga_node] = 0;
	pq.emplace(0, giga_node);
	ll res = 0;
	while (!pq.empty())
	{
		const auto [c, cur] = pq.top();
		pq.pop();
		visited[cur] = true;
		res = max(res, (ll)c);
		for (const auto [cost, next] : tree[cur])
		{
			if (visited[next])continue;
			pq.emplace(cost + c, next);
		}
	}
	cout << giga_dist << ' ' << res;
}