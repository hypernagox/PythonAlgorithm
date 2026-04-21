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
int files[501];
int n;
int acc[501];
int memo[501][501];
int GetAcc(const int l, const int r)
{
    return acc[r] - acc[l] + files[l];
}
int GO(const int l, const int r)
{
    if (l >= r)return 0;
    auto& ref = memo[l][r];
    if (ref)return ref;
    int min_v = INF;
    const auto v = GetAcc(l, r);
    for (int k = l; k < r; ++k)
    {
        min_v = min(min_v, v + GO(l, k) +
            GO(k + 1, r));
    }
    return ref = min_v;
}
void Solve() noexcept
{
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        int k = 0;
        for (int i = 0; i < n; ++i) 
        {
            cin >> files[i];
            k += files[i];
            acc[i] = k;
        }
        memset(memo, 0, sizeof(memo));
        cout << GO(0, n - 1) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}