#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;
int arr[100001];
bool visited[100001];
bool done[100001];
int res;
void go(const int n)
{
    if (visited[n]) {
        if (!done[n])
        {
            for (int i = arr[n]; i != n; i = arr[i])
                ++res;
            ++res;
        }
        return;
    }
    visited[n] = 1;
    go(arr[n]);
    done[n] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n; cin >> t;
    while (t--) {
        res = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) { cin >> arr[i]; visited[i] = done[i] = 0; }
        for (int i = 1; i <= n; ++i) {
            if (visited[i])continue;
            go(i);
        }
        cout << n - res << '\n';
    }
}