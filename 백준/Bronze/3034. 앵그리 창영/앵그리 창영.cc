#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 1e9;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
void Solve()noexcept
{
    int n, a, b; cin >> n >> a >> b;
    const auto hori = a * a + b * b;
    while (n--)
    {
        int x; cin >> x;
        if (x * x <= hori)
        {
            cout << "DA\n";
        }
        else
        {
            cout << "NE\n";
        }
    }
}
int main()
{
    FastIO();
    Solve();
}