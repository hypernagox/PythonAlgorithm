#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int MAX_VAL = 987654321;
int arr[1001];
int n, m;
int memo[1001][1001];
int GO(const int idx,const int cur_cap)
{
	if (idx == n)
	{
		return 0;
	}
	auto& ref = memo[idx][cur_cap];
	if (~ref)return ref;
	int a = MAX_VAL;
	int b = MAX_VAL;
	// 지금 줄에 넣기
	if (cur_cap > arr[idx])
	{
		a = GO(idx + 1, cur_cap - arr[idx] - 1);
	}
	else if (cur_cap == arr[idx])
	{
		a = GO(idx + 1, m);
	}
	// 다음 줄에 넣기
	b = GO(idx + 1, m - arr[idx] - 1) + (cur_cap + 1) * (cur_cap + 1);
	return ref = min(a, b);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	memset(memo, -1, sizeof(memo));
	cout << GO(0, m);
}