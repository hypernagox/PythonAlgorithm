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
    string a, b; cin >> a >> b;
    queue<string> q;
    q.emplace(b);
    set<string> visited;
    while (q.size())
    {
        auto cur = move(q.front());
        q.pop();
        if (cur.empty())continue;
        if (cur == a)
        {
            cout << 1;
            return;
        }
        if (!visited.emplace(cur).second)continue;
        if (cur.back() == 'A')
        {
            cur.pop_back();
            q.emplace(move(cur));
        }
        else if (cur.back() == 'B')
        {
            cur.pop_back();
            reverse(cur.begin(), cur.end());
            q.emplace(move(cur));
        }
    }
    cout << 0;
}
int main()
{
    FastIO();
    Solve();
}