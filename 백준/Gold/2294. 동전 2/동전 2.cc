#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int coins[101];
int n, k;
int dp[200001];
constexpr int INF = 987654321;
int sol(int sum)
{
    if (sum == k) return 0;   // 딱 맞으면 더 안 써도 됨
    if (sum > k) return INF;  // 넘쳤으면 실패 경로

    int& ref = dp[sum];
    if (ref != -1) return ref;

    ref = INF;
    for (int i = 0; i < n; ++i)
    {
        // sum + coins[i] 에서 시작했을 때의 비용 + 1
        ref = min(ref, sol(sum + coins[i]) + 1);
    }
    return ref;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> coins[i];
	}
    for (auto& i : dp)i = -1;
	//sol(0);
    int res = sol(0);
    if (res >= INF) cout << -1;
    else cout << res;
}