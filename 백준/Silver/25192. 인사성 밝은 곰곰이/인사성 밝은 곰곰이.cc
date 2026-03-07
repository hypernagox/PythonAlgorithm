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
void Solve()noexcept
{
    int n; cin >> n;
    int ans = 0;
    bool flag = false;
    set<string> s;
    while (n--)
    {
        string msg; cin >> msg;
        if ("ENTER" == msg)
        {
            ans += s.size();
            s.clear();
        }
        else
        {
            s.emplace(move(msg));
        }
    }
    cout << ans + s.size();
}
int main()
{
    FastIO();
    Solve();
}