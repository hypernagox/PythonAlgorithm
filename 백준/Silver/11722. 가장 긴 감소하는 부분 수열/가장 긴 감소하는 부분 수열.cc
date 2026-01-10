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
int GO(const int idx,const int prev_idx)
{
    if (idx == n)return 0;
    auto& ref = memo[idx][prev_idx + 1];
    if (~ref)return ref;
    int a = 0;
    int b = 0;
    // 지금 인덱스 쓰자.
    if(prev_idx==-1 || arr[prev_idx] > arr[idx])
        a = GO(idx + 1, idx) + 1;

    // 지금 인덱스 안쓴다.
    b = GO(idx + 1, prev_idx);
    return ref = max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(0, -1);
}