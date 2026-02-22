#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
void Solve()noexcept
{
    int t; cin >> t;
    while (t--)
    {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        const long long dx = x1 - x2;
        const long long dy = y1 - y2;
        const long long d2 = dx * dx + dy * dy;
        if (d2 == 0)
        {
            if (r1 == r2) cout << -1 << '\n';
            else cout << 0 << '\n';
            continue;
        }
        const long long sum = r1 + r2;
        const long long diff = llabs(r1 - r2);
        const long long sum2 = sum * sum;
        const long long diff2 = diff * diff;
        if (d2 > sum2) cout << 0 << '\n';
        else if (d2 < diff2) cout << 0 << '\n';
        else if (d2 == sum2) cout << 1 << '\n';
        else if (d2 == diff2) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}