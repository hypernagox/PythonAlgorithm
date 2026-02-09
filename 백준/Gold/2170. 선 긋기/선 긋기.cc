#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pll> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    long long sum = v[0].second - v[0].first;
    int cur_idx = 0;
    for (int i = 1; i < n; ++i)
    {
        if (v[cur_idx].second < v[i].second)
        {
            sum += v[i].second - max(v[cur_idx].second, v[i].first);
            cur_idx = i;
        }
    }
    cout << sum;
}