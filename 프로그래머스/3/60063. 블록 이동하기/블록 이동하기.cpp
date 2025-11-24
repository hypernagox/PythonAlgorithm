#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
constexpr const int dy[]{-1,0,1,0};
constexpr const int dx[]{0,1,0,-1};
struct Robot
{
    pi first;
    pi second;
    const auto operator<(const Robot& r)const{
        if(first == r.first)return second <r.second;
        return first<r.first;
    }
    Robot(pi a,pi b):first{a},second{b}{}
};
bool IsOK(const vector<vector<int>>& board, const int ny,const int nx)
{
    if(ny < 0 || nx < 0 || ny >=board.size() || nx >=board.back().size())return false;
    if(board[ny][nx])return false;
    return true;
}
set<Robot> visited;
vector<Robot> GetSpace(const vector<vector<int>>& board, const Robot& cur)
{
    vector<Robot> res;
    const int n = static_cast<int>(board.size());
    const int m = static_cast<int>(board[0].size());

    const auto [y1, x1] = cur.first;
    const auto [y2, x2] = cur.second;

    // 1. 상하좌우로 "통째로" 이동
    for (int dir = 0; dir < 4; ++dir)
    {
        const int ny1 = y1 + dy[dir];
        const int nx1 = x1 + dx[dir];
        const int ny2 = y2 + dy[dir];
        const int nx2 = x2 + dx[dir];

        if (ny1 < 0 || nx1 < 0 || ny2 < 0 || nx2 < 0 ||
            ny1 >= n || nx1 >= m || ny2 >= n || nx2 >= m)
        {
            continue;
        }

        if (board[ny1][nx1] || board[ny2][nx2]) continue;

        Robot next{{ny1, nx1}, {ny2, nx2}};
        if (!visited.emplace(next).second) continue;
        res.emplace_back(next);
    }

    // 2. 회전
    // 가로로 누워 있는 경우 (y1 == y2)
    if (y1 == y2)
    {
        // 위로 회전
        int ny = y1 - 1;
        if (ny >= 0 && !board[ny][x1] && !board[ny][x2])
        {
            // 왼쪽 칸을 축으로 위로 회전
            Robot r1{{ny, x1}, {y1, x1}};
            if (visited.emplace(r1).second) res.emplace_back(r1);

            // 오른쪽 칸을 축으로 위로 회전
            Robot r2{{ny, x2}, {y2, x2}};
            if (visited.emplace(r2).second) res.emplace_back(r2);
        }

        // 아래로 회전
        ny = y1 + 1;
        if (ny < n && !board[ny][x1] && !board[ny][x2])
        {
            Robot r1{{y1, x1}, {ny, x1}};
            if (visited.emplace(r1).second) res.emplace_back(r1);

            Robot r2{{y2, x2}, {ny, x2}};
            if (visited.emplace(r2).second) res.emplace_back(r2);
        }
    }
    // 세로로 서 있는 경우 (x1 == x2)
    else if (x1 == x2)
    {
        // 왼쪽으로 회전
        int nx = x1 - 1;
        if (nx >= 0 && !board[y1][nx] && !board[y2][nx])
        {
            Robot r1{{y1, nx}, {y1, x1}};
            if (visited.emplace(r1).second) res.emplace_back(r1);

            Robot r2{{y2, nx}, {y2, x2}};
            if (visited.emplace(r2).second) res.emplace_back(r2);
        }

        // 오른쪽으로 회전
        nx = x1 + 1;
        if (nx < m && !board[y1][nx] && !board[y2][nx])
        {
            Robot r1{{y1, x1}, {y1, nx}};
            if (visited.emplace(r1).second) res.emplace_back(r1);

            Robot r2{{y2, x2}, {y2, nx}};
            if (visited.emplace(r2).second) res.emplace_back(r2);
        }
    }

    return res;
}
int solution(vector<vector<int>> board)
{
    int answer = 987654321;
    Robot start{{0,0},{0,1}};
    queue<pair<Robot,int>> q;
    q.emplace(start,0);
    visited.emplace(start);
    const auto N = (int)board.size() - 1;
    while(!q.empty())
    {
        const auto [cur,cost]=q.front();
        q.pop();
        if(cur.first ==make_pair(N,N) || cur.second == make_pair(N,N))
        {
            answer = min(answer,cost);
          //  break;
        }
        const auto nexts = GetSpace(board,cur);
        for(const auto next:nexts)
        {
            q.emplace(next,cost+1);
        }
    }
    return answer;
}