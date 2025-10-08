#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int score[]{ 3,2,1,0,1,2,3 };
string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    vector<pair<string, pair<int, int>>> mbti
    {
        {"RT",{0,0}},
        {"CF",{0,0}},
        {"JM",{0,0}},
        {"AN",{0,0}},
    };
    for (int i = 0; i < survey.size(); ++i)
    {
        const auto type = (choices[i] < 4) ? survey[i][0] : survey[i][1];
        for (auto& [s, p] : mbti)
        {
            const auto idx = s.find(type);
            if (idx != string::npos)
            {
                if (idx == 0)
                {
                    p.first += score[choices[i] - 1];
                }
                else
                {
                    p.second += score[choices[i] - 1];
                }
            }
        }
    }
    for (auto& [type, nums] : mbti)
    {
        if (nums.first > nums.second)
        {
            answer.push_back(type[0]);
        }
        else if (nums.first < nums.second)
        {
            answer.push_back(type[1]);
        }
        else
        {
            auto temp = type;
            sort(temp.begin(), temp.end());
            answer.push_back(temp[0]);
        }
    }
    return answer;
}