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
ll memo[91];
ll GO(const int num)
{
    if (num == 0)return 0;
    if (num == 1)return 1;
    if (num == 2)return 1;
    auto& ref = memo[num];
    if (ref)return ref;
    return ref = GO(num - 1) + GO(num - 2);
}
void Solve() noexcept
{
    // 1
    // 10
    // 100 101
    // 100 + ? , 101 + ?
    // 1000 1001 1010
    // 
    int n; cin >> n;
    cout << GO(n);
}
int main()
{
    FastIO();
    Solve();
}