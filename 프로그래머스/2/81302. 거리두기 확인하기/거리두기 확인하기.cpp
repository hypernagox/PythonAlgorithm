#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
int GetDist(int y1,int x1,int y2,int x2)
{
    return abs(y1-y2)+abs(x1-x2);
}
int sol(const vector<string>& room)
{
    vector<pi> peoples;
    for(int i=0;i<room.size();++i)
    {
        for(int j=0;j<room[i].size();++j)
        {
            if(room[i][j]=='P')
            {
                peoples.emplace_back(i,j);
            }
        }
    }
    for(int i=0;i<peoples.size();++i)
    {
        const auto [cur_y, cur_x] = peoples[i];
        for(int j=i+1;j<peoples.size();++j)
        {
            const auto [y, x] = peoples[j];
            const auto d = GetDist(cur_y,cur_x,y,x);
            if(d <= 2)
            {
                if(d<=1)return 0;
                if(cur_y == y)
                {
                    if(room[y][max(cur_x,x) - 1] != 'X')
                    {
                        return 0;
                    }
                }
                else if(cur_x ==x)
                {
                    if(room[max(cur_y,y) - 1][x] != 'X')
                    {
                        return 0;
                    }
                }
                else
                {
                    const pi p1{cur_y,x};
                    const pi p2{y,cur_x};
                    if(!(room[cur_y][x] == room[y][cur_x] && room[cur_y][x] == 'X'))
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for(const auto& room : places)
    {
        answer.emplace_back(sol(room));
    }
    return answer;
}