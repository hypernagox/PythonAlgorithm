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
void Solve()noexcept
{
    string str; cin >> str;
    string stack;
    int cnt[2]{};
    for (const auto ch : str)
    {
        if (stack.empty() || stack.back() == ch)
        {
            stack.push_back(ch);
            continue;
        }
        ++cnt[stack.back() - '0'];
        stack.clear();
        stack.push_back(ch);
    }
    ++cnt[stack.back() - '0'];
    cout << min(cnt[0], cnt[1]);
}
int main()
{
    FastIO();
    Solve();
}