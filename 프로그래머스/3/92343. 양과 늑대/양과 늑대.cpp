#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> adj[18];
vector<int> infos;
int ans;
void GO(const int cur_node, int sheep, int wolf, set<int> visitable_list)
{
    if (infos[cur_node])++wolf;
    else ++sheep;
    ans = max(ans, sheep);
    if (sheep <= wolf)return;
    visitable_list.erase(cur_node); // 이 리스트를 이용해서 나를 온거니 나를 날린다.
    set<int> deliver_list_to_child{ visitable_list }; 
    for (const auto next : adj[cur_node])deliver_list_to_child.emplace(next); // 현재까지 정보에 지금 나로부터 갈수있는 녀석들을 추가
    for (const auto child : deliver_list_to_child)
    {
        GO(child, sheep, wolf, deliver_list_to_child);// 자식에게 지금까지 방문 가능한 노드들을 전달한다.
    }
}
int solution(vector<int> info, vector<vector<int>> edges)
{
    info.swap(infos);
    for (const auto& edge : edges)
    {
        adj[edge[0]].emplace_back(edge[1]);
    }
    GO(0, 0, 0, {});
    return ans;
}