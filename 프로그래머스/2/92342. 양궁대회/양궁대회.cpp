#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int CalculateScoreDiff(const vector<int>& info, const vector<int>& lists)
{
    int rion = 0;
    int appeach = 0;
    for (int i = 0; i < lists.size(); ++i)
    {
        if (info[i] == lists[i] && info[i] == 0)continue;
        if (info[i] < lists[i])
        {
            // 어피치가 확실하게 작은경우
            rion += 10 - i;
        }
        else
        {
            appeach += 10 - i;
            // 어피치가 같거나 크다
        }
    }
    return rion - appeach;
}
vector<pair<vector<int>,int>> list_and_score;
set<vector<int>> visited;
bool Cmp(const vector<int>& a, const vector<int>& b)
{
    for (int i = a.size(); i >= 0; --i)
    {
        if (a[i] == b[i])continue;
        return a[i] > b[i];
    }
    return false;
}
void GO(const vector<int>& info, const int n, vector<int>& lists)
{
    if (0 == n)
    {
        const auto diff = CalculateScoreDiff(info, lists);
        if (diff > 0)
        {
            list_and_score.emplace_back(lists, diff);
        }
        return;
    }
    if (!visited.emplace(lists).second)return;
    for (int i = 0; i < lists.size(); ++i)
    {
        lists[i]++;
        GO(info, n - 1, lists);
        lists[i]--;
    }
}
vector<int> solution(int n, vector<int> info)
{
    vector<int> list(info.size(), 0);
    GO(info, n, list);
    if (list_and_score.empty())return vector<int>{-1};
    int max_score = -1;
    for (const auto& [list, score] : list_and_score)
    {
        if (max_score < score)
        {
            max_score = score;
        }
    }
    vector<vector<int>> res;
    for (auto& [list, score] : list_and_score)
    {
        if (max_score == score)
        {
            res.emplace_back(move(list));
        }
    }
    sort(res.begin(), res.end(),Cmp);
    return res.front();
}