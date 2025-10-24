#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
struct DisjointSet
{
    bool Union(int a, int b)
    {
        a = FindParent(a);
        b = FindParent(b);
        if (a == b)return false;
        if (a > b)swap(a, b);
        parents[b] = a;
        return true;
    }
    int FindParent(const int n) {
        return parents[n] == n ? n : parents[n] = FindParent(parents[n]);
    }
    vector<int> parents;
    DisjointSet(int n)
    {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }
};
int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
        });
    DisjointSet dis{ n };
    for (const auto& edge : costs)
    {
        if (dis.Union(edge[0], edge[1]))
        {
            answer += edge[2];
        }
    }
    return answer;
}