#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
int coins[101];
int n, k;
int memo[10001];
int GO(const int cur_money)
{
    if (cur_money == 0)return 0;
    if (cur_money < 0)return INF;
    auto& ref = memo[cur_money];
    if (ref)return ref;
    ref = INF;
    for (int i = 0; i < n; ++i)
    {
        ref = min(ref, GO(cur_money - coins[i]) + 1);
    }
    return ref;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)cin >> coins[i];
    const auto ans = GO(k);
    if (ans < INF)cout << ans;
    else cout << -1;
}