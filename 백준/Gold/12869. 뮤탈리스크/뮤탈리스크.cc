#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<const int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int memo[61][61][61];
int GO(const int a, const int b, const int c)
{
    auto& ref = memo[max(a, 0)][max(b, 0)][max(c, 0)];
    if (a <= 0 && b <= 0 && c <= 0)
    {
        return ref = 0;
    }
    if (ref)return ref;
    const auto v1 = GO(a - 9, b - 3, c - 1);
    const auto v2 = GO(a - 3, b - 9, c - 1);
    const auto v3 = GO(a - 3, b - 1, c - 9);
    const auto v4 = GO(a - 9, b - 1, c - 3);
    const auto v5 = GO(a - 1, b - 9, c - 3);
    const auto v6 = GO(a - 1, b - 3, c - 9);
    return ref = 1 + min({ v1,v2,v3,v4,v5,v6 });
}
void Solve()noexcept
{
    int n; cin >> n;
    int arr[3]{};
    for (int i = 0; i < n; ++i)cin >> arr[i];
    cout << GO(arr[0], arr[1], arr[2]);
}
int main()
{
    FastIO();
    Solve();
}