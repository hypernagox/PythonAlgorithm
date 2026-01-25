#include <bits/stdc++.h>
using namespace std;
int main() 
{
  ios::sync_with_stdio(false);cin.tie(nullptr);
  for (;;) 
  {
    int n; cin >> n;
    if (n == 0)
      break;
    const int totalBlocks = n * (n + 1) / 2;
    cout << totalBlocks << '\n';
  }
}