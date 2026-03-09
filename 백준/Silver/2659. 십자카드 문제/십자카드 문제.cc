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
vector<string> v;
string num;
set<string> s;
void GO(const int cur, const int start)
{
    if (4 == cur)
    {
        set<string> ss;
        for (int i = 0; i < 4; ++i)
        {
            ss.emplace(num);
            rotate(num.begin(), num.begin() + 1, num.end());
        }
        if (s.emplace(*ss.begin()).second)
        {
            v.emplace_back(*ss.begin());
        }
        return;
    }
    for (int i = 1; i <= 9; ++i)
    {
        num.push_back(i + '0');
        GO(cur + 1, i);
        num.pop_back();
    }
}
void Solve()noexcept
{
    GO(0, 1);
    string target;
    for (int i = 0; i < 4; ++i)
    {
        char a; cin >> a;
        target += a;
    }
    set<string> ss;
    for (int i = 0; i < 4; ++i)
    {
        ss.emplace(target);
        rotate(target.begin(), target.begin() + 1, target.end());
    }
    cout << find(v.begin(), v.end(), *ss.begin()) - v.begin() + 1;
}
int main()
{
    FastIO();
    Solve();
}