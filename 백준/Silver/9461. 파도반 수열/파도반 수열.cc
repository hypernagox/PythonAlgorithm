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
ull memo[101];
ull GO(const int n)
{
    if (1 == n)return 1;
    if (2 == n)return 1;
    if (3 == n)return 1;
    if (4 == n)return 2;
    if (5 == n)return 2;
    if (memo[n])return memo[n];
    return memo[n] = GO(n - 1) + GO(n - 5);
}
void Solve()noexcept
{
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        cout << GO(x) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}