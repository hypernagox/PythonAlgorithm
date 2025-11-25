#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int t, w;
int table[1004];
int dp[2][1004][34];
int aa = 0;
int sol(const int pos, const int cur_time,const int move_count)
{
	auto& ref = dp[pos][cur_time][move_count];
	if (cur_time == t)
	{
		return 0;
	}
	if (ref)return ref;
	// 움직인다
	int a = 0;
	int b = 0;
	if (move_count - 1 >= 0)
	{
		a = sol(pos ^ 1, cur_time + 1, move_count - 1);
	}
	// 안움직인다
	b = sol(pos, cur_time + 1, move_count);
	return ref = max(a, b) + (table[cur_time] == pos);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t >> w;
	for (int i = 0; i < t; ++i)
	{
		cin >> table[i];
		table[i]--;
	}
	cout << max(sol(0, 0, w), sol(1, 0, w - 1));
	//int a = 10;
	//cout << max({dp[0][t],dp[0]})
}