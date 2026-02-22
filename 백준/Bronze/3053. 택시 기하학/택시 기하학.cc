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
    double r;
    cin >> r;

    cout << fixed;
    cout.precision(6);
    cout << 3.14159265358979323846 * r * r << "\n";
    cout << 2 * r * r;
}
int main()
{
    FastIO();
    Solve();
}