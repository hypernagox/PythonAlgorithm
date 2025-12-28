#include <bits/stdc++.h>
using namespace std;
constexpr const int dy[]{-1,0,1,0};
constexpr const int dx[]{0,1,0,-1};
int Y;
int X;
bool visited[101][101][4][2];
vector<string> mat;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
void GO(const char target, const int y, const int x, const int prev_dir, const bool change_dir)
{
    if(visited[y][x][prev_dir][change_dir])
    {
        return;
    }
    visited[y][x][prev_dir][change_dir]=true;
    if(change_dir)
    {
        const auto ny = y + dy[prev_dir];
        const auto nx = x + dx[prev_dir];
        if(ny < 0 || nx < 0 || ny >= Y || nx >= X)return;
        if(mat[ny][nx] == '.'|| mat[ny][nx] == target)GO(target,ny,nx,prev_dir,change_dir);
    }
    else
    {
        for(int i=0;i<4;++i)
        {
            const auto ny = y + dy[i];
            const auto nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= Y || nx >= X)continue;
            if(mat[ny][nx] == '.' || mat[ny][nx] == target)
            {
                GO(target,ny,nx,i,prev_dir != i);
            }
        }
    }
    
}
string solution(int m, int n, vector<string> board) 
{
    Y = m;
    X = n;
    mat.swap(board);
    vector<pair<int,int>> targets[26];
    int cnt = 0;
    for(int i=0;i<Y;++i)
    {
        for(int j=0;j<X;++j)
        {
            const auto val = mat[i][j];
            if(isalpha(val))
            {
                // 알파벳쌍을 모은다
                targets[val - 'A'].emplace_back(i,j);
                ++cnt;
            }
        }
    }
    string answer = "";
    for(int i=0;i<26;++i)
    {
        if(targets[i].empty())continue;
        const auto [sy,sx] = targets[i][0];
        const auto [ey,ex] = targets[i][1];
        memset(visited,0,sizeof(visited));
        for(int k=0;k<4;++k)
        {
             GO(i+'A',sy,sx,k,false);
        }
        for(int k=0;k<4;++k)
        {
             if(visited[ey][ex][k][0] || visited[ey][ex][k][1])
        {
            answer += (i+'A');
            mat[sy][sx] ='.';
            mat[ey][ex] = '.';
            targets[i].clear();
            i = -1;
            break;
        }
        }
       
    }
    //sort(answer.begin(),answer.end());
    if(answer.size() != cnt / 2)return "IMPOSSIBLE";
    return answer;
}