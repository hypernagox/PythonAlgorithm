#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> solution(vector<int> numbers)
{
    vector<int> answer; answer.reserve(numbers.size());
    vector<int> stack; stack.reserve(numbers.size());
    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        while (!stack.empty() && stack.back() <= numbers[i])stack.pop_back();
        if (stack.empty())
        {
            answer.emplace_back(-1);
        }
        else
        {
            answer.emplace_back(stack.back());
        }
        stack.emplace_back(numbers[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}