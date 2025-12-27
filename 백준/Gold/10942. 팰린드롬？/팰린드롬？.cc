#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int arr[2002];
int memo[2002][2002];
int GO(const int l, const int r)
{
    if (l >= r)
    {
        return 1;
    }
    auto& ref = memo[l][r];
    if (-1 != ref)return ref;
    if (arr[l] == arr[r])
    {
        return ref = GO(l + 1, r - 1);
    }
    else
    {
        return ref = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    int m; cin >> m;
    memset(memo, -1, sizeof(memo));
    while (m--)
    {
        int a, b; cin >> a >> b;
        cout << GO(a - 1, b - 1)<<'\n';
    }
}