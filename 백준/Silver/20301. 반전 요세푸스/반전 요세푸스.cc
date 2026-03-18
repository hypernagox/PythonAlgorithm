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
    int n, k, m;
    cin >> n >> k >> m;
    deque<int> dq;
    for (int i = 1; i <= n; ++i)
    {
        dq.push_back(i);
    }
    bool forward = true;
    int removed = 0;
    while (!dq.empty())
    {
        if (forward)
        {
            for (int i = 0; i < k - 1; ++i)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << dq.front() << '\n';
            dq.pop_front();
        }
        else
        {
            for (int i = 0; i < k - 1; ++i)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back() << '\n';
            dq.pop_back();
        }
        ++removed;
        if (removed % m == 0)
        {
            forward = !forward;
        }
    }
}
int main()
{
    FastIO();
    Solve();
}