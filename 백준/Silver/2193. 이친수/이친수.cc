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
ll memo[91][2];
ll GO(const int num, const int last)
{
    if (num == 1)return last;
    if (num == 2)return !last;
    auto& ref = memo[num][last];
    if (ref)return ref;
    if (last)
    {
        return ref = GO(num - 1, 0);
    }
    else
    {
        return ref = GO(num - 1, 0) + GO(num - 1, 1);
    }
}
void Solve() noexcept
{
    int n; cin >> n;
    cout << GO(n, 0) + GO(n, 1);
}
int main()
{
    FastIO();
    Solve();
}