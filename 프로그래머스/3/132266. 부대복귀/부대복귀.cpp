#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100001];
int visited[100001];
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<int> answer;
    for(const auto& e:roads)
    {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
    }
    queue<int> q;
    q.emplace(destination);
    visited[destination]=1;
    while(!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        for(const auto next:adj[cur])
        {
            if(visited[next])continue;
            visited[next]=visited[cur] + 1;
            q.emplace(next);
        }
    }
    for(const auto d : sources)
    {
        if(0 == d)
        {
             answer.emplace_back(-1);
        }
        else
        {
            answer.emplace_back(visited[d]-1);
        }
    }
    return answer;
}