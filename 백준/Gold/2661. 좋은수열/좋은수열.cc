#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
bool Check(const string& cur)
{
    const int len = cur.size() / 2;
    const auto s = cur.data();
    for (int i = 1; i <= len; ++i)
    {
        const string_view s1{ cur.data() + ((int)cur.size()) - i,(ull)i };
        const string_view s2{ cur.data() + ((int)cur.size()) - i - i,(ull)i };
        if (s1 == s2)return false;
    }
    return true;
}
void GO(string& cur)
{
    if (!Check(cur))return;
    if (cur.size() == n)
    {
        cout << cur;
        exit(0);
        return;
    }
    for (int i = 1; i <= 3; ++i)
    {
        cur.push_back('0' + i);
        GO(cur);
        cur.pop_back();
    }
}
void Solve()noexcept
{
    cin >> n;
    string cur; cur.reserve(81);
    GO(cur);
}
int main()
{
    FastIO();
    Solve();
}