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
    vector<int> v;
    map<int,int> sorted;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    vector<int> temp{ v };
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; ++i)
    {
        sorted.emplace(temp[i], i);
    }
    int cnt = 0;
    vector<deque<int>> deq;
    for (int i = 0; i < v.size(); ++i)
    {
        const auto cur_idx = sorted[v[i]];
        bool flag = true;
        for (auto& d : deq)
        {
            const auto f = sorted[d.front()];
            const auto b = sorted[d.back()];
            if (f == cur_idx + 1)
            {
                flag = false;
                d.emplace_front(v[i]);
                break;
            }
            else if (b == cur_idx - 1)
            {
                flag = false;
                d.emplace_back(v[i]);
                break;
            }
        }
        if (flag)
        {
            deq.emplace_back(deque<int>{v[i]});
            ++cnt;
        }
    }
    cout << cnt;

}
int main()
{
    FastIO();
    Solve();
}