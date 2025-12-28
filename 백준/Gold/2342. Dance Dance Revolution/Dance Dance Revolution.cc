#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
struct Data
{
    int left = 0;
    int right = 0;
    int cost = 0;
    int idx = 0;
    const auto operator<(const Data& d)const {
        return cost > d.cost;
    }
};
int arr[100001];
int n = 0;
//int best[100001];
bool visited[5][5][100001];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 100001; ++i)
    {
        cin >> arr[i];
        if (arr[i] == 0)break;
        ++n;
    }
    //for (auto& i : best)i = INF;
    priority_queue<Data> pq;
    pq.emplace(Data{});
    set<int> res;
    while (!pq.empty())
    {
        const auto [l, r, c, i] = pq.top();
        pq.pop();
        if (i == n)
        {
           // cout << c;
            res.emplace(c);
            continue;
        }
        if (visited[l][r][i])continue;
        visited[l][r][i] = true;
        //if (best[i] < c)
        //{
        //    continue;
        //}
        const auto cur_target = arr[i];
        // 같다면 처리
        if (l == cur_target)
        {
           // if (best[i] > c + 1)
            {
               // best[i] = c + 1;
                pq.emplace(l, r, c + 1, i + 1);
            }
        }
        else if (r == cur_target)
        {
            //if (best[i] > c + 1)
            {
                //best[i] = c + 1;
                pq.emplace(l, r, c + 1, i + 1);
            }
           
        }
        else
        {
            // 왼발 움직여보기
            {
                const auto diff = abs(l - cur_target);
                if ((diff == 1 || diff == 3) && l)
                {
                    //if (best[i] > c + 3)
                    {
                        //best[i] = c + 3;
                        pq.emplace(cur_target, r, c + 3, i + 1);
                    }
                    
                }
                else if(diff == 2 && l)
                {
                    //if (best[i] > c + 4)
                    {
                       // best[i] = c + 4;
                        pq.emplace(cur_target, r, c + 4, i + 1);
                    }
                   
                }
                else
                {
                   // if (best[i] > c + 2)
                    {
                       // best[i] = c + 2;
                        pq.emplace(cur_target, r, c + 2, i + 1);
                    }
                }
            }
            // 오른발 움직여보기
            {
                const auto diff = abs(r - cur_target);
                if ((diff == 1 || diff == 3 )&& r)
                {
                    //if (best[i] > c + 3)
                    {
                        //best[i] = c + 3;
                        pq.emplace(l, cur_target, c + 3, i + 1);
                    }
                   
                }
                else if (diff == 2 && r)
                {
                    //if (best[i] > c + 4)
                    {
                        //best[i] = c + 4;
                        pq.emplace(l, cur_target, c + 4, i + 1);
                    }
                    
                }
                else
                {
                    //if (best[i] > c + 2)
                    {
                        //best[i] = c + 2;
                        pq.emplace(l, cur_target, c + 2, i + 1);
                    }
                   
                }
            }
        }
    }
    cout << *res.begin();
}