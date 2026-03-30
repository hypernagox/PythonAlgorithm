#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
map<char, function<int(int)>> m;
string ToRegister(int s)
{
    auto temp = to_string(s);
    while (temp.size() != 4)temp.insert(temp.begin(), '0');
    return temp;
}
int D(int s)
{
    return (s * 2) % 10000;
}
int S(int s)
{
    auto n = (s);
    if (n == 0)n = 9999;
    else --n;
    return ((n));
}
int L(int x)
{
    return (x % 1000) * 10 + x / 1000;
}

int R(int x)
{
    return (x % 10) * 1000 + x / 10;
}
constexpr const char commands[]{ "DSLR" };
//bool visited[10000];
//string visited[10000];
char visited[10000];
int SS, EE;
unordered_map<int, int> parents;
void GO(const int n)
{
    if (n == SS)return;
    GO(parents[n]);
    cout << visited[n];
}
void Solve() noexcept
{
    int t; cin >> t;
    m['D'] = D;
    m['S'] = S;
    m['L'] = L;
    m['R'] = R;
    string start, end;
    //unordered_set<string> visited; visited.reserve(1024);
    deque<int> q;
    parents.reserve(1024);
    //string res;
    //res.reserve(1000);
    while (t--)
    {
        cin >> start >> end;
        start = ToRegister(stoi(start));
        end = ToRegister(stoi(end));
        //visited.emplace(start);
        //visited[stoi(start)] = 1;
       // map<int, string> visited;
        visited[stoi(start)] = '*';
        
        parents[stoi(start)] = stoi(start);
        q.emplace_front(stoi(start));
        EE = stoi(end);
        SS = stoi(start);
        while (q.size())
        {
            const int cur = move(q.front());
            q.pop_front();
            
            if (EE == cur)
            {
                GO(cur);
                //int now = (cur);
                //while (now != S)
                //{
                //    res.push_back(visited[(now)]);
                //    now = parents[now];
                //    
                //}
                //reverse(res.begin(), res.end());
                //cout << res << '\n';
                //res.clear();
                //cout << visited[stoi(cur)] << '\n';
                ////cout << path << '\n';
                break;
            }
            for (int i = 0; i < 4; ++i)
            {
                auto next = m[commands[i]](cur);
                //auto& path = visited[next];
                if (visited[(next)])continue;
                //auto t = visited[stoi(cur)];
                //t.push_back(commands[i]);
                visited[(next)] = commands[i];
               // const auto num = stoi(next);
                //if (visited[num])continue;
                //visited[num] = 1;
                //auto temp = path;
                //temp.push_back(commands[i]);
                parents[(next)] = (cur);
                q.emplace_back((next));
            }
            
        }
        memset(visited, 0, sizeof(visited));
       // visited.clear();
        q.clear();
        parents.clear();
        cout << '\n';
       // for (auto& s : visited)s.clear();
    }
}
int main()
{
    FastIO();
    Solve();
}