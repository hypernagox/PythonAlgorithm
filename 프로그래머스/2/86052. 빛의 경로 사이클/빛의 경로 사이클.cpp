#include <bits/stdc++.h>
using namespace std;
constexpr const int dy[]{-1,0,1,0};
constexpr const int dx[]{0,1,0,-1};
vector<string> g;
//    0
// 3      1
//    2
//int state[501][501];
bool visited[501][501][4];
vector<int> answer;
void GO(const int y,const int x, const int dir, const int cnt)
{
    auto ny = y + dy[dir];
    auto nx = x + dx[dir];
    if(ny < 0)ny = g.size() - 1;
    if(nx < 0)nx = g.back().size() - 1;
    if(ny >= g.size())ny = 0;
    if(nx >= g.back().size())nx = 0;
    //if(state[ny][nx] == 1)
    //{
    //    answer.emplace_back(cnt);
    //    return;
    //}
    const auto d = g[ny][nx];
    int next_dir =dir;
    if('L'== d)
    {
        next_dir = (dir - 1 + 4) % 4;
    }
    else if('R' == d)
    {
        next_dir = (dir + 1) % 4;
    }
    if(visited[ny][nx][next_dir])
    {
        answer.emplace_back(cnt);
        return;
    }
    visited[ny][nx][next_dir] = 1;
   // state[ny][nx] = 1;
    GO(ny,nx,next_dir,cnt+1);
    //state[ny][nx] = 2;
}
vector<int> solution(vector<string> grid) 
{
    g = grid;
    for(int i=0;i<grid.size();++i)
    {
        for(int j=0;j<grid.back().size();++j)
        {
            for(int k=0;k<4;++k)
            {
                if(visited[i][j][k])continue;
                //visited[i][j][k]=1;
                GO(i,j,k,0);
                //memset(state,0,sizeof(state));
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}