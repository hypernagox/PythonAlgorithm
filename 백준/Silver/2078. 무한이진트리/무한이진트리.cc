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
void Solve()noexcept
{
    long long a, b; cin >> a >> b;
    long long l = 0;
    long long r = 0;
    while (!(a == 1 && b == 1))
    {
        if (a > b)
        {
            const long long q = (a - 1) / b;
            a -= q * b;
            l += q;
        }
        else
        {
            const long long q = (b - 1) / a;
            b -= q * a;
            r += q;
        }
    }
    cout << l << ' ' << r;
}
int main()
{
    FastIO();
    Solve();
}