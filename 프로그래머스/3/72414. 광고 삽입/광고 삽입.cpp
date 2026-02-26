#include <bits/stdc++.h>
using namespace std;
long long Time2Int(const string& time)
{
    const auto h = time.substr(0,2);
    const auto m = time.substr(3,2);
    const auto s = time.substr(6,2);
    return stoll(h) * 3600 + stoll(m) * 60 + stoll(s);
}
string Int2Time(const long long sec)
{
    const long long h = sec / 3600;
    const long long m = (sec % 3600) / 60;
    const long long s = sec % 60;
    ostringstream oss;
    oss << setw(2) << setfill('0') << h << ":"
        << setw(2) << setfill('0') << m << ":"
        << setw(2) << setfill('0') << s;
    return oss.str();
}
string solution(string play_time, string adv_time, vector<string> logs)
{
    const auto total_play_time = Time2Int(play_time);
    const auto adv = Time2Int(adv_time);
    vector<long long> delta_play(total_play_time + 2);
    vector<long long> viewer(total_play_time + 2);
    vector<long long> acc_viewer(total_play_time + 2);
    for(const auto& t: logs)
    {
        const auto s = Time2Int(t.substr(0,8));
        const auto e = Time2Int(t.substr(9,8));
        delta_play[s]++;
        delta_play[e]--;
    }
    viewer[0] = delta_play[0];
    for(int i=1;i<delta_play.size();++i)
    {
       acc_viewer[i] = acc_viewer[i-1]+viewer[i-1];
       viewer[i] = delta_play[i] + viewer[i-1];
    }
    long long max_val = -1;
    long long ans = 0;
    for(int i=0;i<=total_play_time - adv;++i)
    {
        const auto v = acc_viewer[i + adv] - acc_viewer[i]; // i지점에서 끝났을때 누적합
        if(max_val < v)
        {
            max_val = v;
            ans = i;
        }
    }
    return Int2Time(ans);
}