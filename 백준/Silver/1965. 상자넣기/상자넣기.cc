#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
int arr[1001];
int memo[1001][1001];
int GO(const int i, const int prev_idx)
{
    if (i == -1)return 0;
    auto& ref = memo[i][prev_idx + 1];
    if (~ref)return ref;
    int a = 0;
    int b = 0;
    if (-1 == prev_idx || arr[prev_idx] > arr[i])
    {
        // 선택한다.
        a = GO(i - 1, i) + 1;
    }
    // 선택하지 않는다.
    b = GO(i - 1, prev_idx);
    return ref = max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(n - 1, -1);
}