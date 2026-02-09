#include <bits/stdc++.h>
using namespace std;
long long GetNum(const long long cur_num, unordered_map<long long, long long>& m)
{
    const auto iter = m.find(cur_num);
    if(m.end() == iter)
    {
        m.emplace(cur_num, cur_num + 1);
        return cur_num + 1;
    }
    else
    {
        return iter->second = GetNum(iter->second, m);
    }
}
vector<long long> solution(long long k, vector<long long> room_number) 
{
    vector<long long> answer;
    unordered_map<long long, long long> m;
    answer.reserve(room_number.size());
    m.reserve(room_number.size());
    for(const auto i : room_number)
    {
        answer.emplace_back(GetNum(i, m) - 1);
    }
    return answer;
}