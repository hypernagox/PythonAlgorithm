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
int arr[101];
int n, m;
int NUM;
bool visited[101];
int indicies[101];
int GO(const int idx)
{
    if (idx == m)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                cnt += arr[i] < arr[j];
            }
        }
        return cnt == NUM;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])continue;
        visited[i] = 1;
        arr[indicies[idx]] = i;
        res += GO(idx + 1);
        arr[indicies[idx]] = 0;
        visited[i] = 0;
    }
    return res;
}
void Solve() noexcept
{
    cin >> n >> NUM;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        visited[arr[i]] = 1;
        m += arr[i] == 0;
        if (arr[i] == 0)
        {
            indicies[cnt++] = i;
        }
    }
    cout << GO(0);
}
int main()
{
    FastIO();
    Solve();
}