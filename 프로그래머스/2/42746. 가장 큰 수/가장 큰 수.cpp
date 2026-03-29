#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
string solution(vector<int> numbers) 
{
    vector<string> v;
    for(const auto n : numbers)
    {
        v.emplace_back(to_string(n));
    }
    sort(v.begin(),v.end(),[](const auto& a,const auto& b){
        for(int i=0;i<min(a.size(),b.size());++i)
        {
            if(a[i]==b[i])continue;
            return a[i] > b[i];
        }
        return a + b > b + a;
    });
    string answer{};
    for(const auto& s : v)answer += s;
    if(answer[0]=='0')return "0";
    return answer;
}