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
pi arr[200001];
void Solve()noexcept
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        pq.emplace(arr[i].second);
        if (pq.size() > arr[i].first)pq.pop();
    }
    int res = 0;
    while (pq.size())
    {
        res += pq.top();
        pq.pop();
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}