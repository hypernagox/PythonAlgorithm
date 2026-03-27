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
int cards[1001];
int n;
int memo[1001][1001];
int GO(const int idx, const int cur_cards)
{
    if (cur_cards > n)return -INF;
    if (cur_cards == n)return 0;
    if (idx == n)return cur_cards == n ? 0 : -INF;
    auto& ref = memo[idx][cur_cards];
    if (~ref)return ref;
    const auto a = GO(idx + 0, cur_cards + idx + 1) + cards[idx]; // 고려한다
    const auto b = GO(idx + 1, cur_cards); // 재낀다
    return ref = max(a, b);
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> cards[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}
int main()
{
    FastIO();
    Solve();
}