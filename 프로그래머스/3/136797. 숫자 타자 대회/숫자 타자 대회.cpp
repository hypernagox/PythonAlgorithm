#include <bits/stdc++.h>
using namespace std;
int dists[12][12][12][12];
constexpr const int dy[]{-1,-1,0,1,1,1,0,-1};
constexpr const int dx[]{0,1,1,1,0,-1,-1,-1};
struct Data
{
    int y,x;
    int cost;
    const auto operator<(const Data& d)const{
        return cost > d.cost;
    }
    Data(int a,int b,int c):y{a},x{b},cost{c}{}
};
int memo[12][12][200001];
pair<int,int> GetRC(int num)
{
    if (num == 0) return {3, 1};
    if(num)--num;
    return make_pair(num/3,num%3);
}
void Dij(const int num)
{
    const auto [sy,sx] = GetRC(num);
    dists[sy][sx][sy][sx]=0;
    priority_queue<Data> pq;
    pq.emplace(sy,sx,0);
    while(!pq.empty())
    {
        const auto [y,x,cost] = pq.top();
        pq.pop();
        if(dists[sy][sx][y][x] < cost)continue;
        for(int k=0;k<8;++k)
        {
            const auto ny = y + dy[k];
            const auto nx = x + dx[k];
            int c = 2;
            if(ny != y && nx != x)++c;
            if(ny < 0 || nx < 0 || ny >= 4 || nx >= 3)continue;
            if(ny == 3 && (nx == 0 || nx == 2)) continue;
            const auto new_cost = cost + c;
            if(dists[sy][sx][ny][nx] > new_cost)
            {
                dists[sy][sx][ny][nx] = new_cost;
                pq.emplace(ny,nx,new_cost);
            }
        }
    }
}
string n;
int GetDist(const int num1, const int num2)
{
    const auto [y1,x1] = GetRC(num1);
    const auto [y2,x2] = GetRC(num2);
    return dists[y1][x1][y2][x2];
}
int GO(const int idx, const int cur_l, const int cur_r)
{
    if(idx == -1)return 0;
    auto& ref = memo[cur_l][cur_r][idx];
    if(~ref)return ref;
    const auto target_num = n[idx] - '0';
    int target = target_num;
    const auto [ny,nx]=GetRC(target);
    int a = 987654321;
    int b = 987654321;
    if(target_num == cur_l)
    {
        a = GO(idx - 1,cur_l,cur_r) + 1;
    }
    else if(target_num == cur_r)
    {
        b = GO(idx - 1,cur_l,cur_r) + 1;
    }
    else
    {
         a = GO(idx - 1,target_num,cur_r) + GetDist(cur_l,target_num);
         b = GO(idx - 1,cur_l,target_num) + GetDist(cur_r,target_num);
    }
    return ref = min(a,b);
}
int solution(string numbers)
{
    n.swap(numbers);
    constexpr int INF = 987654321;
    fill(&dists[0][0][0][0], &dists[0][0][0][0] + 12*12*12*12, INF);
    memset(memo,-1,sizeof(memo));
    for(int i=1;i<=9;++i)Dij(i);
    Dij(0);
    reverse(n.begin(),n.end());
    return GO(n.size() - 1,4,6);
}