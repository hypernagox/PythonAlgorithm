#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<int> v1, v2;
int n, c;
int items[31];
void GO(const int idx, const int limit, const int sum, vector<int>& v)
{
    if (sum > c)return;
    if (idx == limit)
    {
        v.emplace_back(sum);
        return;
    }
    // 담는다.
    GO(idx + 1, limit, sum + items[idx], v);
    //안담는다
    GO(idx + 1, limit, sum, v);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; ++i)cin >> items[i];
    GO(0, n / 2, 0, v1);
    GO(n / 2, n, 0, v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ull res = 0;
    for (const auto w : v1)
    {
        const auto val = c - w;
        if (val >= 0)
        {
            res += upper_bound(v2.begin(), v2.end(), val) - v2.begin();
        }
    }
    cout << res;
}