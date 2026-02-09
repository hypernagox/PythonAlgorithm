#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
constexpr const pi blocks[5][5]
{
{
{1,0},
{1,1},
{1,2},
{0,1},
{0,2}
},

{
{1,0},
{2,0},
{2,-1},
{0,-1},
{1,-1}
},

{
{1,0},
{2,0},
{2,1},
{0,1},
{1,1}
},

{
{1,0},
{1,-1},
{1,-2},
{0,-1},
{0,-2}
},

{
{1,-1},
{1,0},
{1,1},
{0,-1},
{0,1}
},
};
vector<vector<int>> b;
bool CanGo(const int y,const int x)
{
    if(y<0 || x<0 || y>=b.size() || x>=b.back().size())return false;
    return true;
}
bool CanDelete(const int y,const int x)
{
    auto yy = y;
    auto xx = x;
    while(CanGo(yy,xx))
    {
        if(b[yy][xx])return false;
        yy -= 1;
    }
    return true;
}
bool Check(const int y,const int x)
{
    const auto val = b[y][x];
    int num = -1;
    for(int t = 0; t<5;++t)
    {
        num = t;
        const auto& B = blocks[t];
        for(int i=0;i<3;++i)
        {
            const auto ny = y + B[i].first;
            const auto nx = x + B[i].second;
            if(!CanGo(ny,nx)){num = -1;break;}
            if(val != b[ny][nx]){num = -1;break;}
        }
        for(int i=3;i<5;++i)
        {
            const auto ny = y + B[i].first;
            const auto nx = x + B[i].second;
            if(!CanGo(ny,nx)){num = -1;break;}
            if(b[ny][nx]){num = -1;break;}
        }
        if(-1 != num)break;
    }
    if(-1 == num)return false;
    for(int i=3;i<5;++i)
    {
        const auto ny = y + blocks[num][i].first;
        const auto nx = x + blocks[num][i].second;
        if(!CanDelete(ny,nx))return false;
    }
    b[y][x] = 0;
    for(int i=0;i<3;++i)
    {
        const auto ny = y + blocks[num][i].first;
        const auto nx = x + blocks[num][i].second;
        b[ny][nx] = 0;
    }
    return true;
}
int solution(vector<vector<int>> board)
{
    int answer = 0;
    bool flag = false;
    b.swap(board);
    do
    {
        flag = false;
        for(int i=0;i<b.size();++i)
        {
            for(int j=0;j<b.back().size();++j)
            {
                if(b[i][j] && Check(i,j))
                {
                    flag=true;
                    ++answer;
                }
            }
        }
    }while(flag);
    return answer;
}