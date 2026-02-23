#include <bits/stdc++.h>
using namespace std;
int N;
int Y;
const int INF = (int)(1e9);
int memo[1000001];
int GO(const int X)
{
    if(X > Y)return INF;
    if(X == Y)return 0;
    auto& ref = memo[X];
    if(~ref)return ref;
    const int a = GO(X + N);
    const int b = GO(X * 2);
    const int c = GO(X * 3);
    return ref = 1 + min({a,b,c});
}
int solution(int x, int y, int n) 
{
    N=n;
    Y=y;
    memset(memo,-1,sizeof(memo));
    const auto answer = GO(x);
    return answer >= INF ? -1 : answer;
}