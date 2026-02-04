#include <bits/stdc++.h>
using namespace std;
constexpr const int dy[]{-1,0,1,0};
constexpr const int dx[]{0,1,0,-1};
int bestDists[26][26][4];
struct Data
{
    int y;
    int x;
    int cost;
    int dir;
    const auto operator<(const Data& d)const {
        return cost > d.cost;
    }
    Data(int a,int b,int c,int d):y{a},x{b},cost{c},dir{d}{}
};
int solution(vector<vector<int>> board) 
{
    priority_queue<Data> pq;
    fill(&bestDists[0][0][0],&bestDists[0][0][0]+(26*26*4),987654321);
    for(int i=0;i<4;++i)
    {
         pq.emplace(0,0,0,i);
        bestDists[0][0][i]=0;
    }
    while(!pq.empty())
    {
        const auto[y,x,cost,dir]=pq.top();
        pq.pop();
        if(bestDists[y][x][dir] < cost)continue;
        for(int i=0;i<4;++i)
        {
            const auto ny = y + dy[i];
            const auto nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board.back().size())continue;
            if(board[ny][nx])continue;
            int c = 100;
            if(-1 != dir && dir != i)c+=500;
            const auto new_cost = cost + c;
            if(bestDists[ny][nx][dir] > new_cost)
            {
                bestDists[ny][nx][dir] = new_cost;
                pq.emplace(ny,nx,new_cost,i);
            }
        }
    }
    return *min_element(
        bestDists[board.size()-1][board.back().size()-1],
        bestDists[board.size()-1][board.back().size()-1] + 4
        );
}