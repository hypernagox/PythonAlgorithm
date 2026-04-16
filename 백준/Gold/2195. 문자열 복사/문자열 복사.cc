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
    int i = 0;
    while (i < s2.size())
    {
        int maxLen = 0;
        for (int j = 0; j < s1.size(); ++j)
        {
            int k = 0;
            while (i + k < s2.size() && j + k < s1.size() && s2[i + k] == s1[j + k])
            {
                ++k;
            }
            maxLen = max(maxLen, k);
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