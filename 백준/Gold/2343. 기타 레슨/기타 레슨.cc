#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int arr[100001];
int n, m;
bool Check(const long long mid)
{
    long long sum = 0;
    long long cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > mid)return false;
        const auto next_sum = sum + (long long)arr[i];
        if (next_sum > mid)
        {
            ++cnt;
            sum = arr[i];
        }
        else
        {
            sum = next_sum;
        }
    }
    return cnt <= m;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    long long l = 0;
    long long r = 1LL << 62;
    while (l < r)
    {
        const auto mid = (l + r) / 2LL;
        if (Check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
}