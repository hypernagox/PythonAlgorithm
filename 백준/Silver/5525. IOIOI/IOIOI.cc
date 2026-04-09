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
void Solve() noexcept
{
    string s;
    int n, m; cin >> n >> m >> s;
    int ans = 0;
    char prev = 'O';
    int icount = 0;
    int ocount = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (prev == 'O' && s[i] == 'I')
        {
            ++icount;
            if (icount == n + 1 && ocount == n)
            {
                ++ans;
                icount--;
                ocount--;
            }
        }
        else if (prev == 'I' && s[i] == 'O')
        {
            ++ocount;
        }
        else
        {
            icount = 0;
            ocount = 0;
            if (s[i] == 'I')++icount;
        }
        prev = s[i];
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}