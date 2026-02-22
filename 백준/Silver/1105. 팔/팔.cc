#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
void Solve()noexcept
{
    string l, r; cin >> l >> r;
    if (l.size() != r.size())
    {
        cout << 0;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < l.size(); ++i)
    {
        if (l[i] == r[i] && l[i] == '8')
        {
            ++cnt;
        }
        else if (l[i] != r[i])
        {
            break;
        }
    }
    cout << cnt;
}
int main()
{
    FastIO();
    Solve();
}