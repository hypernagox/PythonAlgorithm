#include <bits/stdc++.h>
using namespace std;
bool CanGo(const string& a, const string& b)
{
    int cnt = 0;
    for(int i=0;i<a.size();++i)
    {
        cnt += a[i] != b[i];
    }
    return cnt <= 1;
}
int solution(string begin, string target, vector<string> words)
{
    map<string,int> visited;
    queue<string> q;
    q.emplace(begin);
    visited[begin]=0;
    while(q.size())
    {
        const auto cur = q.front();
        q.pop();
        if(cur == target)break;
        for(const auto& next :words)
        {
            if(visited.count(next))continue;
            if(!CanGo(cur,next))continue;
            q.emplace(next);
            visited[next]=visited[cur]+1;
        }
    }
    return visited[target];
}