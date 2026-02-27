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
string nums[16];
int mods[16];
int pow10mod[51];
int n, k;
ll memo[1 << 15][101];
ll GO(const int bits, const int mod)
{
    if (bits == ((1 << n) - 1))return mod ? 0 : 1;
    auto& ref = memo[bits][mod];
    if (~ref)return ref;
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        const auto bit = (1 << i);
        if (bits & bit)continue;
        const auto next_mod = (mod * pow10mod[nums[i].size()] + mods[i]) % k;
        res += GO(bits | bit, next_mod);
    }
    return ref = res;
}
ll GCD(const ll a, const ll b)
{
    return b ? GCD(b, a % b) : a;
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cin >> k;
    for (int i = 0; i < n; ++i)
    {
        int r = 0;
        for (const auto ch : nums[i])
        {
            r = (r * 10 + ('0' - ch)) % k;
        }
        mods[i] = r;
    }
    pow10mod[0] = 1 % k;
    for (int i = 1; i < 51; ++i)
    {
        pow10mod[i] = (pow10mod[i - 1] * 10) % k;
    }
    ll pac = 1;
    for (int i = 1; i <= n; ++i)pac *= i;
    memset(memo, -1, sizeof(memo));
    const auto v = GO(0, 0);
    const auto g = GCD(v, pac);
    cout << v / g << '/' << pac / g;
}
int main()
{
    FastIO();
    Solve();
}