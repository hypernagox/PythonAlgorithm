#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int Time2Int(const string& str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}
struct Homework
{
    string name;
    int start_time;
    int play_time;
    Homework(const string& a, int b, int c) :name{ a }, start_time{ b }, play_time{ c } {}
    int GetFinishTime()const noexcept { return  start_time + play_time; }
    const auto operator<(const Homework& a)const noexcept {
        return start_time < a.start_time;
    }
};
vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    vector<Homework> homeworks;
    vector<Homework> remains;
    for (const auto& data : plans)
    {
        homeworks.emplace_back(data[0], Time2Int(data[1]), stoi(data[2]));
    }
    sort(homeworks.begin(), homeworks.end());
    Homework cur_homework = homeworks[0];
    for (int i = 1; i < homeworks.size(); ++i)
    {
        const auto cur_final = cur_homework.GetFinishTime();
        const auto next_start = homeworks[i].start_time;
        const auto diff = cur_final - next_start;
        if (diff <= 0)
        {
            // 일단 과제 끝내긴한거
            answer.emplace_back(cur_homework.name);
            if (remains.empty() || 0 == diff)
            {
                cur_homework = homeworks[i];
            }
            else
            {
                const auto r = remains.back();
                remains.pop_back();
                cur_homework = r;
                cur_homework.start_time = cur_final;
                --i;
            }
        }
        else
        {
            cur_homework.start_time = homeworks[i].GetFinishTime();
            cur_homework.play_time = diff;
            remains.emplace_back(cur_homework);
            cur_homework = homeworks[i];
        }
    }
    answer.emplace_back(cur_homework.name);
    while (!remains.empty())
    {
        answer.emplace_back(remains.back().name);
        remains.pop_back();
    }
    return answer;
}

