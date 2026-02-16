#include <bits/stdc++.h>
using namespace std;
int ta,tb;
int A,B;
vector<int> customers;
int ex_temper;
constexpr const int INF = 987654321;
bool IsOk(const int temper)
{
    return temper >= ta && temper <= tb;
}
int GetTemperDir(const int temper)
{
    if(ex_temper > temper)
    {
        return 1;
    }
    else if(ex_temper < temper)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int memo[1001][200][2];
int GO(const int idx, const int cur_temper, const bool cur_on)
{
    if(idx == customers.size()) return 0;
    if(customers[idx] == 1 && !IsOk(cur_temper))
    {
        return INF;
    }
    auto& ref = memo[idx][cur_temper + 50][cur_on];
    if(~ref) return ref;
    if(cur_on) // 에어컨이 켜져있던 경우
    {
        int a = INF, b = INF;
        // 온도 범위(-10~40)를 벗어나지 않도록 체크
        if(cur_temper + 1 <= 40) a = GO(idx+1, cur_temper + 1, 1) + A;
        if(cur_temper - 1 >= -10) b = GO(idx+1, cur_temper - 1, 1) + A;
        
        const int c = GO(idx+1, cur_temper, 1) + B;
        const int d = GO(idx+1, cur_temper + GetTemperDir(cur_temper), 0); // 끄기
        return ref = min({a, b, c, d});
    }
    else 
    {
        // 꺼진 상태 유지 (자연 변화)
        const int a = GO(idx + 1, cur_temper + GetTemperDir(cur_temper), 0);
        
        int b = INF, c = INF;
        if(cur_temper + 1 <= 40) b = GO(idx+1, cur_temper + 1, 1) + A; // 켜서 올리기
        if(cur_temper - 1 >= -10) c = GO(idx+1, cur_temper - 1, 1) + A; // 켜서 내리기
        
        const int d = GO(idx+1, cur_temper, 1) + B; // 켜서 유지
        return ref = min({a, b, c, d});
    }
}
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard)
{
    int answer = 0;
    ex_temper=temperature;
    customers=onboard;
    ta=t1;
    tb=t2;
    A = a;
    B = b;
    memset(memo,-1,sizeof(memo));
    const auto aa= GO(0,ex_temper, 1);
    memset(memo,-1,sizeof(memo));
    const auto bb =GO(0,ex_temper,0);
    return min(aa,bb);
}