#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> c;
int visited[9][9];
bool IsFinish()
{
    for(const auto& v:c)
    {
        for(const auto i: v)
        {
            if(i)return false;
        }
    }
    return true;
}
void Rotate(const int y,const int x, const int dir)
{
    constexpr const int dy[]{0, -1,0,1,0};
    constexpr const int dx[]{0, 0,1,0,-1};
    for(int i=0;i<5;++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >=c.size() || nx >= c.back().size())continue;
        c[ny][nx] = (c[ny][nx] + 4 + dir) % 4;
    }
}
int ans = 987654321;
int n;
int GO(const int row, const int col)
{
    if(row == n)
    {
        return IsFinish() ? 0 : 987654321;
    }
    int res = 987654321;
    if(col == n)
    {
        res = 0;
        auto prev_state = c;
        for(int i=0;i<n;++i)
        {
            // 내 윗행을 맞추기 위해 돌려야 하는 횟수
            const auto cnt = (4 - c[row - 1][i]) % 4;
            res += cnt;
            Rotate(row,i,cnt);
        }
        // 다음 호출
        res += GO(row+1,col);
        c.swap(prev_state);
        return res;
    }
    // 모든 회전에 대해서
    for(int i=0;i<4;++i)
    {
        Rotate(0,col,i);
        res = min(res,GO(1,col+1) + i);
        Rotate(0,col,-1 * i);
    }
    return res;
}
int solution(vector<vector<int>> clockHands) 
{
    c.swap(clockHands);
    n = c.size();
    return GO(0,0);
}