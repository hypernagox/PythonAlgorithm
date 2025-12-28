#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
int arr[10001];
int memo[10001][3];
int GO(const int idx, const int cnt)
{
    if (idx == n)
    {
        return 0;
    }
    auto& ref = memo[idx][cnt];
    if (-1 != ref)return ref;
    int a = 0;
    int b = 0;
    // 지금 인덱스를 마신다.
    if (cnt < 2)
    {
        a = GO(idx + 1, cnt + 1) + arr[idx];
    }
    // 지금 인덱스를 마시지 않는다.
    b = GO(idx + 1, 0);
    return ref = max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}