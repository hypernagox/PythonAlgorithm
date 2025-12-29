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
int memo[1001][1001][2];
int GO(const int idx, const int prev_val, const bool flag)
{
    if (idx == n)
    {
        return 1;
    }
    auto& ref = memo[idx][prev_val][flag];
    if (-1 != ref)return ref;
    //ref = 0;
    int a = 0;
    int b = 0;
    // 이제 작아져야한다면
    if (flag)
    {
        // 작아질수있다면
        if (prev_val > arr[idx])
        {
            a = GO(idx + 1, arr[idx], flag) + 1;
        }
        // 그냥 선택하지 않는다.
        b = GO(idx + 1, prev_val, flag);
        return ref = max(a, b);
    }
    // 커져야한다
    else
    {
        // 고를수있다면 선택한다.
        if (prev_val < arr[idx])
        {
            a = GO(idx + 1, arr[idx], false) + 1;
        }
        else if (prev_val > arr[idx])
        {
            // 만약 작아져볼수있다면
            a = GO(idx + 1, arr[idx], true) + 1;
        }
        // 그냥 선택하지 않는다.
        b = GO(idx + 1, prev_val, flag);
        return ref = max(a, b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        // 처음을 누구로?
        res = max(res, GO(i, arr[i], false));
    }
    cout << res;
}