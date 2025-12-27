#include <bits/stdc++.h>
using namespace std;
int board[102][102];
int M,N;
set<pair<int,int>> p;
bool CanGo(const int y,const int x)
{
    if(y <= 0 || x <= 0 || y >N||x>M)return false;
    if(p.count({y,x}))return false;
    return true;
}
long long memo[102][102];
long long GO(const int y,const int x)
{
    if(y == N && x == M)
    {
        return 1;
    }
    auto& ref = memo[y][x];
    if(-1 != ref)return ref;
    ref = 0;
    long long s = 0;
    if(CanGo(y+1,x))
    {
        s += GO(y + 1,x) % 1000000007;
    }
    if(CanGo(y,x + 1))
    {
         s += GO(y,x + 1)% 1000000007;
    }
    return ref = s% 1000000007;
}
int solution(int m, int n, vector<vector<int>> puddles) 
{
    M=m;
    N=n;
    memset(memo,-1,sizeof(memo));
    for(const auto& v:puddles)
    {
        p.emplace(v[1],v[0]);
    }
    return GO(1,1);
}