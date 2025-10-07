#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
unordered_map<string, vector<string>> adj;
unordered_map<string, int> name2money;
unordered_map<string, int> res;
unordered_set<string> visited;
void dfs(const string& cur, int price)
{
    if ("-" == cur || 0 == price)return;
    int commision = price / 10;
    price -= commision;
    res[cur] += price;
    for (const auto& next : adj[cur])
    {
        dfs(next, commision);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    const int N = (int)enroll.size();
    for (int i = 0; i < N; ++i)
    {
        adj[enroll[i]].emplace_back(referral[i]); // refrral의 자식은 enroll
    }
    for (int i = 0; i < seller.size(); ++i)
    {
        //name2money[seller[i]] += amount[i] * 100;
        //res[seller[i]] += amount[i] * 100;
        dfs(seller[i], amount[i] * 100);
    }
   // visited.emplace("-");
   
    for (int i = 0; i < N; ++i)
    {
        answer.emplace_back(res[enroll[i]]);
    }
    return answer;
}