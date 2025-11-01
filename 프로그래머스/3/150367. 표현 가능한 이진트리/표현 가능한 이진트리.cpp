#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string str2bin(const long long N)
{
    string temp;
    auto n = N;
    while(n)
    {
        temp.push_back((n&1) + '0');
        n /= 2;
    }
    int h = 1;
    while(h - 1 < temp.size())
    {
        h *= 2;
    }
    h = (h - 1) - temp.size();
    while(h--)temp.push_back('0');
    reverse(temp.begin(),temp.end());
    return temp;
}
bool dfs(const string& b)
{
   if(1 == b.size() || all_of(b.begin(),b.end(),[](const auto& s){return s =='0';}))return true;
    const auto mid = b.size() / 2;
    return b[mid] == '1' && dfs(b.substr(0,mid)) && dfs(b.substr(mid+1));
}
vector<int> solution(vector<long long> numbers) 
{
    vector<int> answer;
    for(const auto n:numbers)
    {
        answer.emplace_back(dfs(str2bin(n)));
    }
    return answer;
}