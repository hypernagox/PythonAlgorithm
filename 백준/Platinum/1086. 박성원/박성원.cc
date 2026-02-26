#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
string arr[16];
int n, k;
int pow10mod[51];
int pre_mod[16];
ll memo[(1 << 15)][101];
ll GO(const int bits, const int mod)
{
    if (bits == ((1 << n) - 1))return mod ? 0 : 1;
    auto& ref = memo[bits][mod];
    if (~ref)return ref;
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (bits & (1 << i))continue;
        const auto next_mod = ((mod * pow10mod[arr[i].size()]) % k + pre_mod[i] % k) % k;
        res += GO(bits | (1 << i), next_mod);
    }
    return ref = res;
}
ll GCD(const ll a, const ll b)
{
    return (b == 0) ? a : GCD(b, a % b);
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < n; ++i)
    {
        int r = 0;
        for (const auto ch : arr[i])
        {
            r = (r * 10 + (ch - '0')) % k;
        }
        pre_mod[i] = r;
    }
    pow10mod[0] = 1 % k;
    for (int i = 1; i <= 50; ++i)
    {
        pow10mod[i] = (pow10mod[i - 1] * 10LL) % k;
    }
    memset(memo, -1, sizeof(memo));
    ll total = 1;
    for (int i = 1; i <= n; ++i) total *= (ll)i;
    const auto cnt = GO(0, 0);
    const auto div = GCD(total, cnt);
    cout << cnt / div << '/' << total / div;
}
int main()
{
    FastIO();
    Solve();
}