#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
void Solve()noexcept
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<string> strs[11];
        while (n--)
        {
            string temp; cin >> temp;
            strs[temp.size()].emplace_back(move(temp));
        }
        bool flag = true;
        for (int i = 1; i <= 9; ++i)
        {
            for (const auto& s1 : strs[i])
            {
                for (int j = i + 1; j <= 10; ++j)
                {
                    for (const auto& s2 : strs[j])
                    {
                        const string_view sv{ s2.data(),s1.size() };
                        if (s1 == sv)
                        {
                            flag = false;
                            goto END;
                        }
                    }
                }
            }
        }
    END:
        if (flag)cout << "YES\n";
        else cout << "NO\n";
    }
}
void FastIO()noexcept;
int main()
{
    FastIO();
    Solve();
}
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
