#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int temperature_;
int t1_;
int t2_;
int a_;
int b_;
vector<int> onboard_;
int memo[1001][51];
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
int GO(const int idx, const int cur_temper)
{
    if(idx == onboard_.size())return 0;
    if(onboard_[idx] && !IsOk(cur_temper))
    {
        return INF;
    }
    if(cur_temper > 40 || cur_temper < -10)return INF;
    auto& ref = memo[idx][cur_temper + 10];
    if(~ref)return ref;
    const auto dir = GetDeltaDir(cur_temper); // 자연변화 (이게 끈거임)
    const int a = GO(idx + 1, cur_temper + 1) + a_;
    const int b = GO(idx + 1, cur_temper - 1) + a_;
    const int c = GO(idx + 1, cur_temper + dir);
    const int d = GO(idx + 1, cur_temper) + ((0 == dir) ? 0 : b_); // 만약 실외랑같으면 냅두고 다르면 에어컨 켜서 유지
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
    return GO(0,temperature);
}