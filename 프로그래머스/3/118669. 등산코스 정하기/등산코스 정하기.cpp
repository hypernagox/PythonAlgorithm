#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<pair<int, int>> adj[50001];
int bestDist[50001];
unordered_set<int> gate;
unordered_set<int> summit;
vector<pi> answer;
set<pi> p;
pi dijk(const vector<int>& gates)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (const auto i : gates)
    {
        pq.emplace(make_pair(0, i));
        bestDist[i] = 0;
    }
    fill(bestDist, bestDist + 50001, -1);
   // int intensity1 = 0;
    while (!pq.empty())
    {
        const auto [cost, cur] = pq.top();
        pq.pop();
        //intensity1 = max(intensity1, intensity);
        //if (visited[cur])continue;
        //visited[cur] = true;
        if (summit.count(cur))
        {
            //intensity1 = max(intensity1, intensity);
           // cout << cost << "   " << cur << endl << endl;
            //return { cost,cur };
            answer.emplace_back(cost, cur);
            continue;
        }
        if (bestDist[cur] > cost)continue;
        for (const auto [next_c, next] : adj[cur])
        {
            const auto new_cost = next_c;
            //if (visited[next])continue;
            //if (gate.count(next))continue;
            const auto new_intensity = max(next_c, cost);
            if (bestDist[next] > new_intensity || bestDist[next]==-1)
            {
                bestDist[next] = new_intensity;
                pq.emplace(make_pair(new_intensity, next));
            }
        }
    }
    //for (const auto [a, b] : res)
    //{
    //    cout << a << "  " << b << endl << endl;
    //}
    return {};
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    for (const auto& edge : paths)
    {
        adj[edge[0]].emplace_back(edge[2], edge[1]);
        adj[edge[1]].emplace_back(edge[2], edge[0]);
    }
    gate = unordered_set<int>{ gates.begin(),gates.end() };
    summit = unordered_set<int>{ summits.begin(),summits.end() };


   
    //auto r = dijk(gates[0]);
    //for (const auto& point : gates)
    {
        (dijk(gates));
    }
    sort(answer.begin(), answer.end());
    return vector<int>{answer.front().second, answer.front().first};
}