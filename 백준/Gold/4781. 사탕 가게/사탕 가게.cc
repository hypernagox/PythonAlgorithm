#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
int memo[10001];
int GO(const int cur_money, const int n, const int idx,const int cur_sum,const vector<pair<int,int>>& coins)
{
    if (cur_money < 0)return -INF;
   // if (idx == n)return 0;
    auto& ref = memo[cur_money];
    if (ref)return ref;
    // 지금거 산다
    int best = 0;
    for (const auto [cal, cost] : coins)
    {
        best = max(best, GO(cur_money - cost, n, idx, cur_sum + coins[idx].first, coins) + cal);
    }
    return ref = best;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (;;)
    {
        int n;
        string m;
        cin >> n >> m;
        if (n == 0)break;
        string temp;
        for (const auto ch : m)
        {
            if (ch == '.')continue;
            temp.push_back(ch);
        }
        const int money = stoi(temp);
        vector<pair<int,int>> coins;
        for (int i = 0; i < n; ++i)
        {
            int c;
            temp.clear();
            cin >> c >> m;
            for (const auto ch : m)
            {
                if (ch == '.')continue;
                temp.push_back(ch);
            }
            coins.emplace_back(c, stoi(temp));// 칼로리:가격
        }
        cout << GO(money, n, 0, 0, coins) << '\n';
        memset(memo, 0, sizeof(memo));
    }
}