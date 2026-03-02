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
    int n, k; cin >> n >> k;
    int s[101];
    map<int, queue<int>> m;
    for (int i = 0; i < k; ++i)
    {
        int a; cin >> a;
        m[a].emplace(i);
        s[i] = a;
    }
    for (auto& [num, q] : m)
    {
        q.emplace(INF + num);
    }
    map<int, int> sceduler; // 일 / 다음인덱스 
    map<int, int> pq;
    int res = 0;
    for (int i = 0; i < k; ++i)
    {
        if (!sceduler.count(s[i]) && sceduler.size() == n)
        {
            ++res;
            const auto victim = pq.begin()->second;
            sceduler.erase(victim);
            pq.erase(pq.begin());
        }
        m[s[i]].pop();
        const auto next_idx = m[s[i]].front();
        pq.erase(-i);
        sceduler[s[i]] = next_idx;
        pq.emplace(-next_idx, s[i]);
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}
