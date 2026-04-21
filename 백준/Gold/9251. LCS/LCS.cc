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
string s1, s2;
int memo[1001][1001];
int GO(const int i, const int j)
{
    if (i >= s1.size() || j >= s2.size())return 0;
    auto& ref = memo[i][j];
    if (~ref)return ref;
    if (s1[i] == s2[j])
    {
        return ref = GO(i + 1, j + 1) + 1;
    }
    else
    {
        return ref = max(GO(i + 1, j), GO(i, j + 1));
    }
}
void Solve() noexcept
{
    cin >> s1 >> s2;
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}
int main()
{
    FastIO();
    Solve();
}