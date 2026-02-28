#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string solution(long long n, vector<string> bans) 
{
    string answer = "";
    vector<long long> nums;
    nums.reserve(bans.size());
    for(const auto& s: bans)
    {
        ll r = 0;
        for(int i=0;i < s.size(); ++i)
        {
            r = (r * 26) + (s[i] - 'a' + 1);
        }
        nums.emplace_back(r - 0);
    }
    sort(nums.begin(),nums.end());
    for(const auto i : nums)
    {
        if(i <= n)++n;
        else break;
    }
    auto target = n;
    while(target > 0)
    {
        --target;
        const auto rem = (target) % 26LL;
        target /= 26LL;
        answer.push_back('a' + rem);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}