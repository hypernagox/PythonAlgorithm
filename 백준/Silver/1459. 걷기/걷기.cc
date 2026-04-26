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
    ll x, y, w, s; cin >> x >> y >> w >> s;
    ll c1 = INT64_MAX; // 대각
    ll c2 = INT64_MAX; // 평행
    ll c3 = INT64_MAX; // 대각 + 평행
    if ((x + y) & 1)
    {
        c1 = (max(x, y) - 1) * s + w;
    }
    else
    {
        c1 = (max(x, y)) * s;
    }
    c2 = (x + y) * w;
    c3 = min(x, y) * s + abs(x - y) * w;
    cout << min({ c1,c2,c3 });
} 
int main()
{
    FastIO();
    Solve();
}