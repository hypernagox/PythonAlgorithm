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
    string s1, s2; cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < s2.size();)
    {
        int maxLen = 0;
        for (int j = 0; j < s1.size(); ++j)
        {
            int tmp = 0;
            while (j + tmp < s1.length() &&
                i + tmp < s2.length() &&
                s1[j + tmp] == s2[i + tmp])
            {
                ++tmp;
            }
            maxLen = max(maxLen, tmp);
        }
        i += maxLen;
        ++ans;
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}