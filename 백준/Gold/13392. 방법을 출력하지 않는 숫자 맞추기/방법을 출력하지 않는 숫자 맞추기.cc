#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int N;
string startState;
string targetState;
int memo[10001][10];
int GO(const int idx, const int turn) 
{
    if (idx == N) return 0;
    if (~memo[idx][turn]) return memo[idx][turn];
    const int currentNum = (startState[idx] - '0' + turn) % 10;
    const int targetNum = targetState[idx] - '0';
    const int leftMoves = (targetNum - currentNum + 10) % 10;
    const int costLeft = leftMoves + GO(idx + 1, (turn + leftMoves) % 10);
    const int rightMoves = (currentNum - targetNum + 10) % 10;
    const int costRight = rightMoves + GO(idx + 1, turn);
    return memo[idx][turn] = min(costLeft, costRight);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> startState >> targetState;
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}