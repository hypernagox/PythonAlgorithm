#include <bits/stdc++.h>

static long long DoneByTime(long long t, const std::vector<int>& cores)
{
    long long res = (long long)cores.size();
    for (int c : cores)
    {
        res += (t / (long long)c);
    }
    return res;
}

int solution(int n, std::vector<int> cores)
{
    const int m = (int)cores.size();
    if (n <= m)
    {
        return n; 
    }
    long long lo = 0;
    long long hi = 1;
    while (DoneByTime(hi, cores) < n)
    {
        hi <<= 1;
    }
    while (lo < hi)
    {
        long long mid = (lo + hi) / 2;
        if (DoneByTime(mid, cores) >= n)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    const long long t = lo;
    const long long done_before = DoneByTime(t - 1, cores);
    long long cur = done_before;
    for (int i = 0; i < m; ++i)
    {
        if ((t % (long long)cores[i]) == 0)
        {
            ++cur;
            if (cur == n)
            {
                return i + 1;
            }
        }
    }
    return -1;
}
