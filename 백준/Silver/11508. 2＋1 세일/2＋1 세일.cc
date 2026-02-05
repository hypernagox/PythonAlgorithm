#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> pq;
    int n; cin >> n;
    ll res = 0;
    while (n--)
    {
        int a; cin >> a;
        pq.emplace(a);
    }
    while (!pq.empty())
    {
        for (int i = 0; i < 3 && !pq.empty(); ++i)
        {
            const auto v = pq.top();
            pq.pop();
            if (2 == i)break;
            res += v;
        }
    }
    cout << res;
}