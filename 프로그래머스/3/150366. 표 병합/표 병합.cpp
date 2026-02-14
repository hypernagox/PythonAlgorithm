#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
map<pi,pi> parents;
map<pi,string> board;
pi FindParent(const pi cur)
{
    auto& p = parents[cur];
    if(cur == p)return cur;
    else return p = FindParent(p);
}
bool Union(pi a, pi b)
{
    a = FindParent(a);
    b = FindParent(b);
    if(a == b)return false;
    if(a > b)swap(a,b);
    parents[b] = a;
    return true;
}
void Update(const pi pos, const string& word)
{
    const auto p = FindParent(pos);
    board[p] = word;
}
void Merge(const pi pos1, const pi pos2)
{
    pi r1 = FindParent(pos1);
    pi r2 = FindParent(pos2);
    if (r1 == r2) return;
    string v1 = board[r1];
    string v2 = board[r2];
    Union(r1, r2);
    pi root = FindParent(r1);
    pi other = (root == r1 ? r2 : r1);
    string keep = v1.empty() ? v2 : v1;
    board[root] = keep;
}
void UnMerge(const pi target)
{
    const auto pr = FindParent(target);
    const auto val = board[pr];
    vector<pi> targets;
    for(int i=1;i<=50;++i)
    {
        for(int j=1;j<=50;++j)
        {
            const auto p = make_pair(i,j);
            if(FindParent(p) == pr)
            {
                targets.emplace_back(i,j);
            }
        }
    }
    for(const auto p : targets)
    {
        parents[p] = p;
        board[p].clear();
    }
    board[target] = val;
}
string Print(const pi rc)
{
    const auto pr = FindParent(rc);
    const auto& val = board[pr];
    return val.empty() ? "EMPTY" : val;
}
void UpdateAll(const string& from, const string& to)
{
    for (auto& kv : board)
    {
        if (kv.second == from) kv.second = to;
    }
}
vector<string> solution(vector<string> commands)
{
    vector<string> answer;

    parents.clear();
    board.clear();

    for (int i = 1; i <= 50; ++i)
    {
        for (int j = 1; j <= 50; ++j)
        {
            const auto p = make_pair(i, j);
            parents.emplace(p, p);
            board[p] = string{};
        }
    }

    for (const auto& c : commands)
    {
        stringstream ss{c};
        string cmd;
        ss >> cmd;
        if (cmd == "UPDATE")
        {
            string part;
    vector<string> parts;
    // 남은 줄을 모두 읽어서 공백 단위로 분리
    while (ss >> part) {
        parts.push_back(part);
    }

    if (parts.size() == 3) 
    {
        // 인자가 3개면: UPDATE r c value
        int r = stoi(parts[0]);
        int c = stoi(parts[1]);
        string v = parts[2];
        Update({r, c}, v);
    }
    else if (parts.size() == 2)
    {
        // 인자가 2개면: UPDATE val1 val2
        UpdateAll(parts[0], parts[1]);
    }
        }
        else if (cmd == "MERGE")
        {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            Merge({r1, c1}, {r2, c2});
        }
        else if (cmd == "UNMERGE")
        {
            int r, col;
            ss >> r >> col;
            UnMerge({r, col});
        }
        else
        {
            int r, col;
            ss >> r >> col;
            answer.emplace_back(Print({r, col}));
        }
    }
    return answer;
}