#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
map<string, map<string, int>> gift_table;
map<string, int> gift_score_table;
int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;
    for (const auto& line : gifts)
    {
        stringstream sstream{ line };
        string sender, receiver;
        sstream >> sender >> receiver;
        ++gift_table[sender][receiver];
        ++gift_score_table[sender];
        --gift_score_table[receiver];
    }
    map<string, int> res;
    for (int i = 0; i < friends.size(); ++i)
    {
        const auto& friend_a = friends[i];
        for (int j = i + 1; j < friends.size(); ++j)
        {
            const auto& friend_b = friends[j];
            const auto a2b = gift_table[friend_a][friend_b];
            const auto b2a = gift_table[friend_b][friend_a];
            // b가 더 많이줌
            if (a2b < b2a)
            {
                ++res[friend_b];
            }
            else if (a2b > b2a) // a가 더많이줌
            {
                ++res[friend_a];
            }
            else
            {
                // 주고받은수가 같거나 기록이없음
                if (gift_score_table[friend_a] < gift_score_table[friend_b])
                {
                    ++res[friend_b];
                }
                else if (gift_score_table[friend_a] > gift_score_table[friend_b])
                {
                    ++res[friend_a];
                }
                else
                {
                    // 이마저도같으면아무것도안함
                }
            }
        }
    }
    for (const auto& [name, score] : res)answer = max(answer, score);
    return answer;
}