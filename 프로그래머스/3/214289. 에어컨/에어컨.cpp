#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int temperature_;
int t1_;
int t2_;
int a_;
int b_;
vector<int> onboard_;
int memo[1001][51][2];
constexpr const int INF = (int)1e9;
bool IsOk(const int temper)
{
    return t1_ <= temper && temper <= t2_;
}
int GetDeltaDir(const int temper)
{
    if(temper == temperature_)return 0;
    return (temperature_ - temper) / abs(temperature_ - temper);
}
int GO(const int idx, const int cur_temper, const bool is_on)
{
    if(idx == onboard_.size())return 0;
    if(onboard_[idx] && !IsOk(cur_temper))
    {
        return INF;
    }
    if(cur_temper > 40 || cur_temper < -10)return INF;
    auto& ref = memo[idx][cur_temper + 10][is_on];
    if(~ref)return ref;
    const int a = GO(idx + 1, cur_temper + 1, true) + a_;
    const int b = GO(idx + 1, cur_temper - 1, true) + a_;
    const int c = GO(idx + 1, cur_temper + GetDeltaDir(cur_temper), false); // 끈 채로 유지 또는 끈다
    int d = INF;  
    if(is_on)
    {
        d = GO(idx + 1, cur_temper, true) + b_; // 켜져있는데 온도 유지
    }
    return ref = min({a,b,c,d});
}
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard)
{
    temperature_ = temperature;
    t1_ = t1;
    t2_ = t2;
    a_ = a;
    b_ = b;
    onboard_ = onboard;
    memset(memo,-1,sizeof(memo));
    return GO(0,temperature,0);
}