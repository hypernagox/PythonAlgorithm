#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
struct Data
{
    int a, b, c;
};
Data items[1001];
int n;
int memo[1001][3];
int GO(const int idx, const int color)
{
    if (idx == n)
    {
        return 0;
    }
    auto& ref = memo[idx][color];
    if (ref)return ref;
    int a = INF;
    int b = INF;
    if (color == 0)
    {
        a = GO(idx + 1, 1) + items[idx].a;
        b = GO(idx + 1, 2) + items[idx].a;
    }
    else if (color == 1)
    {
        a = GO(idx + 1, 0) + items[idx].b;
        b = GO(idx + 1, 2) + items[idx].b;
    }
    else if (color == 2)
    {
        a = GO(idx + 1, 1) + items[idx].c;
        b = GO(idx + 1, 0) + items[idx].c;
    }
    return ref = min(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].a >> items[i].b >> items[i].c;
    }
    cout << min({ GO(0, 0), GO(0, 1), GO(0, 2) });
}