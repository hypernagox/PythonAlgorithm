#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

struct Data
{
    int counts[10]{}; // arr[i]는 이 문자열에서 i가 몇번 등장했는가 ? , 인덱스는 몇번인가?
    int real_val;
    string str;
    const auto operator<(const Data& d)const noexcept {
        auto a = str + d.str;
        auto b = d.str + str;
        return stoi(a) > stoi(b);
    }
    Data(const int i)
        :real_val{ i }, str{ to_string(i) }
    {
        for (int i = 0; i < str.size(); ++i)
        {
            ++counts[str[i] - '0'];
        }
    }
};
string solution(vector<int> numbers) 
{
    string answer = "";
    vector<Data> d; d.reserve(numbers.size());
    for (const auto i : numbers)
    {
        d.emplace_back(i);
    }
    sort(d.begin(), d.end());
    for (const auto& data : d)
    {
        answer += data.str;
    }
    if (answer[0] == '0')return "0";
    return answer;
}