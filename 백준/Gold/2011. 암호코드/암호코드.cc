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
string pw;
constexpr const ll MOD = 1000000;
ll memo[5001];
ll GO(const int cur)
{
    if (cur >= pw.size())return 1;
    if (pw[cur] == '0')return 0;
    auto& ref = memo[cur];
    if (~ref)return ref;
    ll a = 0;
    ll b = 0;
    // 한글자만 해석
    if (pw[cur] != '0')
    {
        a = (GO(cur + 1)) % MOD;
    }
    // 두글자 해석
    if (pw.size() - cur >= 2)
    {
        const auto num = stoi(pw.substr(cur,2));
        if (num >= 10 && num <= 26)
        {
            b = (GO(cur + 2)) % MOD;
        }
    }
    return ref = (a + b) % MOD;
}
void Solve() noexcept
{
    cin >> pw;
    memset(memo, -1, sizeof(memo));
    cout << GO(0);
}
int main()
{
    FastIO();
    Solve();
}