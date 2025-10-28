#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
constexpr const int dy[]{-1,0,1,0};
constexpr const int dx[]{0,1,0,-1};
struct Game
{
    int cur_cost = 0;
    int cur_select = -1;
    int ans_count = 0;
    int y=0;
    int x=0;
    vector<vector<int>> board;
    const auto operator<(const Game& g)const noexcept{
        if(board == g.board)return make_pair(y,x) <make_pair(g.y,g.x);
        return board < g.board;
    }
};
set<Game> visited;
int solution(vector<vector<int>> board, int r, int c) 
{
    int answer = 0;
    Game g;
    if(board[r][c]!=0)
    {
        g.cur_cost = 1;
        g.cur_select =board[r][c];
        board[r][c]=0;
    }
    else
    {
        
    }
    g.y=r;
    g.x=c;
    g.board=board;
    queue<Game> q;
    q.emplace(g);
    int min_val=987654321;
    visited.emplace(g);
    while(!q.empty())
    {
        const auto cur = move(q.front());
        const auto y =cur.y;
        const auto x =cur.x;
        q.pop();
        bool flag=true;
        for(int i=0;i<4;++i)
         {
             for(int j=0;j<4;++j)
             {
                 if(cur.board[i][j]!=0)
                 {
                     flag =false;
                     break;
                 }
             }
            if(!flag)break;
        }
                              if(flag)
                              {
                                  min_val=min(min_val,cur.cur_cost);
                              }
        for(int k=0;k<4;++k)
        {
            const auto ny = cur.y + dy[k];
            const auto nx = cur.x + dx[k];
            if(ny <0||nx < 0||ny >=4 || nx>=4)continue;
            auto temp =cur;
            temp.cur_cost += 1;
            temp.y=ny;
            temp.x=nx;
            if(temp.board[ny][nx])
            {
                if(temp.cur_select==-1)
                {
                    temp.cur_cost += 1;
                    temp.cur_select=cur.board[ny][nx];
                    temp.board[ny][nx]=0;
                }
                else if(temp.cur_select==cur.board[ny][nx])
                {
                    temp.cur_cost += 1;
                    temp.cur_select=-1;
                    temp.board[ny][nx]=0;
                }
            }
            if(visited.emplace(temp).second)
            {
                q.emplace(temp);
            }
        }
         for(int k=0;k<4;++k)
        {
            auto ny = cur.y ;
            auto nx = cur.x;
             for(;;)
             {
                 const auto nny=ny+dy[k];
                 const auto nnx = nx+dx[k];
                 if(nny <0||nnx < 0||nny >=4 || nnx>=4)break;
                 ny=nny;
                 nx=nnx;
                 if(cur.board[ny][nx])break;
             }
            
            auto temp =cur;
            temp.cur_cost += 1;
            temp.y=ny;
            temp.x=nx;
            if(temp.board[ny][nx])
            {
                if(temp.cur_select==-1)
                {
                    temp.cur_cost += 1;
                    temp.cur_select=cur.board[ny][nx];
                    temp.board[ny][nx]=0;
                }
                else if(temp.cur_select==cur.board[ny][nx])
                {
                    temp.cur_cost += 1;
                    temp.cur_select=-1;
                    temp.board[ny][nx]=0;
                }
            }
            if(visited.emplace(temp).second)
            {
                q.emplace(temp);
            }
        }
    }
    return min_val;
}