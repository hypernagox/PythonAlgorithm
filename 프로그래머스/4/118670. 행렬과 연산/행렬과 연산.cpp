#include <bits/stdc++.h>
using namespace std;
deque<int> l,r;
deque<deque<int>> rows;
void Rotate()
{
    if (rows.empty())
    {
        r.push_front(l.front());
        l.pop_front();
        l.push_back(r.back());
        r.pop_back();
        return;
    }
    r.push_front(rows.front().back());
    rows.front().pop_back();

    rows.back().push_back(r.back());
    r.pop_back();

    l.push_back(rows.back().front());
    rows.back().pop_front();

    rows.front().push_front(l.front());
    l.pop_front();
}
template<typename T>
void Shift(T& deq)
{
    if(deq.empty())return;
    deq.push_front(move(deq.back()));
    deq.pop_back();
}
void Shift()
{
   Shift(l);
   Shift(r);
   Shift(rows);
}
const map<string,function<void(void)>> f
{
    {"Rotate",[](){Rotate();}},
    {"ShiftRow",[](){Shift();}},
};
                
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    l.clear();r.clear();rows.clear();
    vector<vector<int>> answer(rc.size(),vector<int>(rc.back().size(),0));
    for(int i=0;i<rc.size();++i)
    {
        deque<int> temp;
        for(int j=0;j<rc.back().size();++j)
        {
            if(j == 0)
            {
                l.push_back(rc[i][j]);
            }
            else if(j == rc.back().size()-1)
            {
                r.push_back(rc[i][j]);
            }
            else
            {
                temp.push_back(rc[i][j]);
            }
        }
        // 비어있을 때 처리
        if(temp.empty())continue;
        rows.push_back(move(temp));
    }
    for(const auto& op:operations)
    {
        f.find(op)->second();
    }
     for(int i=0;i<rc.size();++i)
    {
        for(int j=0;j<rc.back().size();++j)
        {
            if(j == 0)
            {
                answer[i][j]=l[i];
            }
            else if(j == rc.back().size()-1)
            {
                 answer[i][j]=r[i];
            }
            else
            {
                 answer[i][j]=rows[i][j - 1];
            }
        }
    }
    return answer;
}