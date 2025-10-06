#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

string Convert(int n, int k)
{
    if (n == 0) return "0";
    string res;
    while (n > 0)
    {
        const auto d = n % k;
        res.push_back((char)d + '0');
        n /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}
bool IsPrime(unsigned long long n)
{
    if (n < 2) return false;
    if ((n & 1ULL) == 0ULL) return n == 2ULL;
    for (unsigned long long i = 3; i <= n / i; i += 2)
    {
        if (n % i == 0ULL) return false;
    }
    return true;
}
int solution(int n, int k)
{
    const string target = Convert(n, k);
    string stack; stack.reserve(target.size());
    size_t ans = 0;
    for (const auto ch : target)
    {
        if (ch == '0')
        {
            if (!stack.empty() && IsPrime(stoull(stack)))
            {
                ++ans;
            }
            stack.clear();
        }
        else
        {
            stack.push_back(ch);
        }
    }
    if (!stack.empty())
    {
        ans += IsPrime(stoull(stack));
    }
    return ans;
}