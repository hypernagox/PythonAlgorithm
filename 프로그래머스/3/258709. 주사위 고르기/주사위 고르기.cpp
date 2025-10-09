#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
bool used[11];
vector<vector<int>> dice_combi;
vector<int> combi;
vector<int> res_vec;
long long res = 0;
constexpr const int dices[]{ 0,1,2,3,4,5 };
void CheckSum(const vector<vector<int>>& dice)
{
    vector<int> Aidx;
    vector<int> Bidx;
    for (int i = 0; i < dice.size(); ++i)
    {
        if (used[i]) Aidx.emplace_back(i);
        else Bidx.emplace_back(i);
    }
    const auto BuildSum = [&](const vector<int>& idxs) 
        {
        vector<int> sums{ 0 };
        for (int d : idxs)
        {
            vector<int> next;
            next.reserve(sums.size() * 6);
            for (int s : sums)
            {
                for (int f = 0; f < 6; ++f)
                {
                    next.emplace_back(s + dice[d][f]);
                }
            }
            sums.swap(next);
        }
        return sums;
        };

    vector<int> vs1 = BuildSum(Aidx);
    vector<int> vs2 = BuildSum(Bidx);

    sort(vs1.begin(), vs1.end());
    sort(vs2.begin(), vs2.end());

    long long wins = 0;
    for (const auto sums : vs2)
    {
        const auto iter = upper_bound(vs1.begin(), vs1.end(), sums);
        wins += (vs1.end() - iter);
    }

    if (wins > res)
    {
        res_vec.clear();
        res = wins;
        for (int i = 0; i < dice.size(); ++i)
        {
            if (used[i])
            {
                res_vec.emplace_back(i + 1);
            }
        }
    }
}
void Combi(const vector<vector<int>>& dice, const int cur = 0)
{
    // n / 2 완성 시 비교
    if (dice.size() / 2 == combi.size())
    {
        CheckSum(dice);
        return;
    }
    for (int i = cur; i < dice.size(); ++i)
    {
        used[i] = true;
        combi.emplace_back(i);
        Combi(dice, i + 1);
        combi.pop_back();
        used[i] = false;
    }
}
int N;
void Combi2(vector<int>& dice_num, const int cur = 0)
{
    // n / 2 완성 시 비교
    if (N == cur)
    {
        dice_combi.emplace_back(dice_num);
        return;
    }
    for (int i = 0; i < 6; ++i)
    {
        dice_num.emplace_back(i);
        Combi2(dice_num, cur + 1);
        dice_num.pop_back();
    }
}
vector<int> solution(vector<vector<int>> dice)
{
    N = dice.size();
    vector<int> answer;
    vector<int> dice_num; // 주사위 조합의 경우의 수
    //Combi2(dice_num);
    Combi(dice);
    return res_vec;
}