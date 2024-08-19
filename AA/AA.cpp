#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <ranges>
using namespace std;
vector<int> v[32001];
bool visited[32001];
vector<int> res;
void dfs(int n)
{
	if (visited[n])return;
	visited[n] = true;
	for (auto i : v[n]) {
		if (!visited[i])dfs(i);
	}
	res.emplace_back(n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	res.reserve(n);
	while (m--) {
		int x, y; cin >> x >> y;
		v[x].emplace_back(y);
	}
	for (int i = 1; i <= n; ++i)dfs(i);
	for (auto i : res | views::reverse)cout << i << ' ';
}
