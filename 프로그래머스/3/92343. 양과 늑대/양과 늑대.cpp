#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
bool visited[18];
set<int> ans;
void DFS(
      const vector<int>& info
    , const vector<vector<int>>& edges
    , const int yang
    , const int wolf)noexcept {
    if (yang <= wolf)return;
    ans.emplace(yang);
    for (const auto& v : edges) {
        if (visited[v[0]] && !visited[v[1]]) {
            visited[v[1]] = true;
            if (info[v[1]])DFS(info, edges, yang, wolf + 1);
            else DFS(info, edges, yang + 1, wolf);
            visited[v[1]] = false;
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    visited[0] = true;
    DFS(info, edges, 1, 0);
    return *ans.rbegin();
}