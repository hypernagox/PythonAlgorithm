#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, S;
    while (cin >> N >> S)
    {
        long long x = S / (N + 1);
        cout << x << '\n';
    }

    return 0;
}