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
    int n, k; cin >> n >> k;
    string num; cin >> num;
    int cnt = 0;
    string target; target.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        while (!target.empty() && target.back() < num[i] && cnt < k)
        {
            ++cnt;
            target.pop_back();
        }
        target += num[i];
    }
    while (cnt != k)
    {
        ++cnt;
        target.pop_back();
    }
    cout << target;
}
int main()
{
    FastIO();
    Solve();
}