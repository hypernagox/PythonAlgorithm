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
        vector<string> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            string s; cin >> s;
            v.emplace_back(move(s));
        }
        sort(v.begin(), v.end());
        bool ok = true;
        for (int i = 0; i < (int)v.size() - 1; ++i)
        {
            const string& a = v[i];
            const string& b = v[i + 1];
            if (b.starts_with(a))
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
void FastIO()noexcept;
int main()
{
    FastIO();
    Solve();
}
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }