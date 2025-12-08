#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1000001];
int table[1000001];
constexpr const int INF = 987654321;
int sol(const int cur)
{
	if (cur == 1)
	{
		return 0;
	}
	auto& ref = dp[cur];
	if (ref)return ref;
	int a = INF;
	int b = INF;
	int c = INF;
	if (cur % 3 == 0)
	{
		a = sol(cur / 3) + 1;
	}
	if (cur % 2 == 0)
	{
		b = sol(cur / 2) + 1;
	}
	c = sol(cur - 1) + 1;
	const auto v = min({ a,b,c });
	if (v == a)
	{
		table[cur] = cur / 3;
		//cout << cur / 3 << ' ';
	}
	else if (v == b)
	{
		table[cur] = cur / 2;
		//cout << cur / 2 << ' ';
	}
	else if (v == c)
	{
		table[cur] = cur - 1;
		//cout << cur - 1 << ' ';
	}
	return ref = min({ a,b,c });
}
void PRINT(const int n)
{
	if (table[n] == 0)return;
	cout << table[n] << ' ';
	PRINT((table[n]));
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	cout << sol(n) << '\n' << n << ' ';
	PRINT(n);
}