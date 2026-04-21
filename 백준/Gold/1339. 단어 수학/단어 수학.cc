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
    int n; cin >> n;
    int vals[26]{};
    for (int i = 0; i < n; ++i)
    {
        string temp; cin >> temp;
        for (int j = 0; j < temp.size(); ++j)
        {
            vals[temp[j] - 'A'] += (int)pow(10, temp.size() - j - 1);
        }
    }
    vector<int> v;
    for (int i = 0; i < 26; ++i)
    {
        if (!vals[i])continue;
        v.emplace_back(vals[i]);
    }
    sort(v.begin(), v.end(), greater<int>{});
    ull s = 0;
    int cnt = 9;
    for (const auto i : v)
    {
        s += i * cnt--;
    }
    cout << s;
}
int main()
{
    FastIO();
    Solve();
}