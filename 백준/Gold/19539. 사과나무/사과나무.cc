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
void Solve() noexcept
{
    int n; cin >> n;
    ll s1 = 0;
    ll s2 = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x; cin >> x;
        s1 += x;
        s2 += x / 2LL;
    }
    if (s1 % 3 != 0)
    {
        cout << "NO";
        return;
    }
    s1 /= 3;
    if (s2 >= s1)cout << "YES";
    else cout << "NO";
}
int main()
{
    FastIO();
    Solve();
}