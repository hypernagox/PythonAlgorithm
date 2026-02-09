#include <bits/stdc++.h>
using namespace std;
// d l r u 
constexpr const int dy[]{1,0,0,-1};
constexpr const int dx[]{0,-1,1,0};
constexpr const char dirs[]{"dlru"};
string answer;
string res;
bool flag;
int GetDist(int a1,int b1,int a2,int b2)
{
    return abs(a1-a2) + abs(b1-b2);
}
void GO(int n, int m, int y, int x, int r, int c, int k)
{
    if(flag)return;
    const auto val = k - GetDist(y,x,r,c);
    if(val < 0)return;
    if(val & 1)return;
    if(0 == k && r == y && c == x)
    {
        res=answer;
        flag=true;
        return;
    }
    for(int i=0;i<4;++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if(ny <= 0 || nx <= 0 || ny > n || nx > m)continue;
        answer.push_back(dirs[i]);
        GO(n,m,ny,nx,r,c,k-1);
        answer.pop_back();
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    flag=false;
    res.clear();
    answer.clear();
    GO(n,m,x,y,r,c,k);
    return flag ? res : "impossible";
}