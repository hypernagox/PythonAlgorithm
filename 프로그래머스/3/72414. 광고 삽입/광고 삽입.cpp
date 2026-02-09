#include <bits/stdc++.h>
using namespace std;
long long ToSec(const string& t)
{
    const int h = stoi(t.substr(0, 2));
    const int m = stoi(t.substr(3, 2));
    const int s = stoi(t.substr(6, 2));
    return 1LL * h * 3600 + 1LL * m * 60 + s;
}
string ToTime(long long sec)
{
    long long h = sec / 3600; sec %= 3600;
    long long m = sec / 60;   sec %= 60;
    long long s = sec;
    ostringstream oss;
    oss << setw(2) << setfill('0') << h << ":"
        << setw(2) << setfill('0') << m << ":"
        << setw(2) << setfill('0') << s;
    return oss.str();
}
constexpr const long long ALL_TIME = 100 * 3600 + 1;
long long diff[ALL_TIME];
long long viewers[ALL_TIME];
long long acc_views[ALL_TIME];
string solution(string play_time, string adv_time, vector<string> logs)
{
    const auto p = ToSec(play_time);
    const auto a = ToSec(adv_time);
    for(const auto& log : logs)
    {
        const auto s = ToSec(log.substr(0,8));
        const auto e = ToSec(log.substr(9,8));
        ++diff[s];
        --diff[e];
    }
    for(int i = 1;i <= p;++i)
    {
        viewers[i] = diff[i] + viewers[i-1];
    }
     for(int i = 1;i <= p;++i)
    {
        acc_views[i] = acc_views[i - 1] + viewers[i - 1];
    }
    long long sum = 0;
    long long start = 0;
    for(int i = 0; i + a <= p ; ++i)
    {
        const auto val = acc_views[i + a] - acc_views[i];
        if(sum < val)
        {
            sum = val;
            start = i;
        }
    }
    return ToTime(start);
}