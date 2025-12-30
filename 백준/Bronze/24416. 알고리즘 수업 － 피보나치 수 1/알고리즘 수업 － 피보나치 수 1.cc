#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int k1, k2;
int fib(int n)
{
    if (n == 1 or n == 2)
    { 
        ++k1;
        return 1; 
    }
    else return (fib(n - 1) + fib(n - 2));
}
int fibonacci(int n) 
{
    int f[55]{};
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        ++k2;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    fib(n);
    fibonacci(n);
    cout << k1 << ' ' << k2;
}