#include <bits/stdc++.h>
using namespace std;
long long ToNumber(const string& s)
{
    long long res = 0;
    for (char ch : s)
    {
        res = res * 26 + (ch - 'a' + 1);
    }
    return res;
}
string ToString(long long n)
{
    string temp="";
    while(n)
    {
        --n;
        const auto a = n%26;
        temp.push_back(a + 'a' - 0);
        n /= 26;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<long long> nums;
    for(const auto s:bans)
    {
      // cout<<s<<": "<<ToNumber(s)<<endl;
        nums.emplace_back(ToNumber(s));
    }
    sort(nums.begin(),nums.end());
    //--n;
    for(int i=0;i<nums.size();++i)
    {
        if(nums[i] <= n)
        {
            ++n;
        }
        else
        {
            break;
        }
    }
   // cout<<n<<endl;
    return answer = ToString(n - 0);
}