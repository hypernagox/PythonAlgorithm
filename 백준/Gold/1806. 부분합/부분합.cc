#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
ll arr[100001];
void Solve() noexcept
{
    ll n, s; cin >> n >> s;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ll l = 0;
    ll r = 0;
    ll cur_sum = 0;
    ll len = INF;
    while (r < n)
    {
        cur_sum += arr[r++];
        while (l < r)
        {
            if (cur_sum < s)break;
            len = min(len, r - l);
            cur_sum -= arr[l++];
        }
    }
    if (len >= INF)cout << 0;
    else cout << len;
}
int main()
{
    FastIO();
    Solve();
}