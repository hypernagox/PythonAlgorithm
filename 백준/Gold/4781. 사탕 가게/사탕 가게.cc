#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
vector<pair<int, int>> v;
int memo[10001];
int n, k;
int GO(const int cur_money)
{
    if (cur_money < 0)return -INF;
    auto& ref = memo[cur_money];
    if (ref)return ref;
    int best = 0;
    for (const auto [cal, cost]: v)
    {
        best = max(best, GO(cur_money - cost) + cal);
    }
    return ref = best;
}
int GetMoney(const string_view str)
{
    string temp;
    for (const auto ch : str)
    {
        if (ch == '.')continue;
        temp.push_back(ch);
    }
    return stoi(temp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (;;)
    {
        cin >> n;
        if (n == 0)break;
        v.clear();
        memset(memo, 0, sizeof(memo));
        string temp;
        cin >> temp;
        const auto m = GetMoney(temp);
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a >> temp;
            v.emplace_back(a, GetMoney(temp));
        }
        cout << GO(m) << '\n';
    }
}