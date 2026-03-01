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
int zadu[1001];
int t, w;
int memo[1001][31][2];
int GO(const int idx, const int nokori, const int pos)
{
    if (0 > nokori)return -INF;
    if (idx == t)
    {
        return 0;
    }
    auto& ref = memo[idx][nokori][pos];
    if (~ref)return ref;
    // 움직이기
    const auto a = GO(idx + 1, nokori - 1, pos ^ 1);
    // 안움직이기
    const auto b = GO(idx + 1, nokori, pos);
    return ref = max(a, b) + (pos == zadu[idx]);
}
void Solve()noexcept
{
    cin >> t >> w;
    for (int i = 0; i < t; ++i)
    {
        cin >> zadu[i];
        --zadu[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << max(GO(0, w, 0), GO(0, w - 1, 1));
}
int main()
{
    FastIO();
    Solve();
}