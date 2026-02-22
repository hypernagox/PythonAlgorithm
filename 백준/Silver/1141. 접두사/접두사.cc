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
    int n; cin >> n;
    vector<string> strs[26];
    for (int i = 0; i < n; ++i)
    {
        string temp; cin >> temp;
        strs[temp.front() - 'a'].emplace_back(move(temp));
    }
    for (int i = 0; i < 26; ++i)
    {
        sort(strs[i].begin(), strs[i].end());
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i)
    {
        auto s = strs[i].size();
        if (!s)continue;
        for (int j = 0; j < strs[i].size() - 1; ++j)
        {
            const auto& s1 = strs[i][j];
            const auto& s2 = strs[i][j + 1];
            if (s2.substr(0, s1.size()) == s1)--s;
        }
        ans += s;
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}