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
int L, C;
string s;
vector<string> ans;
bool Check(const string& cur)
{
    int zaum = 0;
    int moum = 0;
    for (const auto c : cur)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')++moum;
        else ++zaum;
    }
    return zaum >= 2 && moum >= 1;
}
void GO(string& cur, const int start)
{
    if (cur.size() == L)
    {
        if (Check(cur))
        {
            cur.push_back('\n');
            ans.emplace_back(cur);
            cur.pop_back();
        }
        return;
    }
    for (int i = start; i < s.size(); ++i)
    {
        const auto c = s[i];
        cur.push_back(c);
        GO(cur, i + 1);
        cur.pop_back();
    }
}
void Solve() noexcept
{
    cin >> L >> C;
    s.reserve(C);
    for (int i = 0; i < C; ++i)
    {
        char x; cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    string temp; temp.reserve(L + 1);
    ans.reserve(1024);
    GO(temp, 0);
    sort(ans.begin(), ans.end());
    for (const auto& str : ans)cout << str;
}
int main()
{
    FastIO();
    Solve();
}