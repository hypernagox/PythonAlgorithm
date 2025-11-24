#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
char mat[502][502];
int n, m;
map<char, pi> dirs
{
	{'U',{-1,0}},
	{'R',{0,1}},
	{'D',{1,0}},
	{'L',{0,-1}},
};
// 0이면 아직모름
// 1이면 불가
// 2면 가능
int state[501][501];
int GO(const int y,const int x)
{
	if (state[y][x])return state[y][x];
	auto& ref = state[y][x];
	const auto [dy, dx] = dirs[mat[y][x]];
	const auto ny = y + dy;
	const auto nx = x + dx;
	if (ny < 0 || nx < 0 || ny >= n || nx >= m)
	{
		return ref = 2;
	}
	if (ref == 1)
	{
		// 온적이있음
		return 1;
	}
	ref = 1;
	return ref = GO(ny, nx);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			const auto v = GO(i, j);
			if (v == 2)++cnt;
		}
	}
	cout << cnt;
}