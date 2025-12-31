#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int n;
int k;
int chu[31];
int orb[8];
int memo[31][65001];
// idx부터 고려하고 차이가 diff일때 가능한가?
int GO(const int idx, const int diff)
{
	if (idx == n)
	{
		if (0 == diff)return 1;
		else return 0;
	}
	if (0 == diff)return 1;
	auto& ref = memo[idx][diff];
	if (-1 != ref)return ref;
	int flag = 0;
	// 추를 더 무거운 곳에 올려 놓는다.
	flag |= GO(idx + 1, diff + chu[idx]);

	// 추를 사용하지 않는다.
	flag |= GO(idx + 1, diff);

	// 추를 현재 더 가벼운 쪽에 올려놓는다.
	flag |= GO(idx + 1, abs(diff - chu[idx]));
	return ref = flag;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> chu[i];
	cin >> k;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < k; ++i)
	{
		int c; cin >> c;
		if (1 == GO(0, c))
		{
			cout << 'Y' << ' ';
		}
		else
		{
			cout << 'N' << ' ';
		}
	}
}