#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int n;
ll arr[301];
ll memo[301][3];
ll GO(const int idx, const int cnt)
{
	if (idx == n - 1)return arr[idx];
	auto& ref = memo[idx][cnt];
	if (ref)return ref;
	ll a = -INF;
	ll b = -INF;
	// 연속해서 오르기
	if (cnt + 1 <= 2)
	{
		a = GO(idx + 1, cnt + 1) + arr[idx];
	}
	// 2개오르기
	if (idx + 2 < n)
	{
		b = GO(idx + 2, 1) + arr[idx];
	}
	return ref = max(a, b);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	cout << max(GO(0, 1), GO(1, 1));
}