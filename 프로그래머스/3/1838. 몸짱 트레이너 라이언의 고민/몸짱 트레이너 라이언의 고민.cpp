#include <bits/stdc++.h>
using namespace std;

bool can_place(int n, int m, int d)
{
    for (int sy = 0; sy < n; ++sy)
    {
        for (int sx = 0; sx < n; ++sx) 
        {
            vector<pair<int, int>> placed;
            placed.push_back({sy, sx});
            
            for (int i = sy * n + sx + 1; i < n * n; ++i)
            {
                int y = i / n;
                int x = i % n;
                bool ok = true;
                for (const auto& p : placed) 
                {
                    if (abs(y - p.first) + abs(x - p.second) < d) 
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok) 
                {
                    placed.push_back({y, x});
                    if ((int)placed.size() == m) return true;
                }
            }
            if ((int)placed.size() >= m) return true;
        }
    }
    return false;
}

int solution(int n, int m, vector<vector<int>> timetable) 
{
    int diff[1322] = {0};
    for (const auto& t : timetable) 
    {
        diff[t[0]]++;
        diff[t[1] + 1]--;
    }
    
    int max_people = 0;
    int current_people = 0;
    for (int i = 600; i <= 1320; ++i) 
    {
        current_people += diff[i];
        max_people = max(max_people, current_people);
    }
    if (max_people <= 1) return 0;
   
    int max_d = 2 * (n - 1);
    for (int d = max_d; d >= 1; --d) 
    {
        if (can_place(n, max_people, d)) 
        {
            return d; 
        }
    }
    return 0;
}