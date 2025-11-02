#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t, n; cin >> n >> t;
	vector<int> vp, vm;
	while (t--)
	{
        vector<ll> pos, neg;
        int zeros = 0;

        for (int i = 0; i < n; ++i) 
        {
            ll x; cin >> x;
            if (x > 0) pos.push_back(x);
            else if (x < 0) neg.push_back(x);
            else zeros++;
        }

        ll res = 1;
        bool used = false;
        for (ll x : pos) 
        {
            res *= x;
            used = true;
        }

        sort(neg.begin(), neg.end());
        for (int i = 0; i + 1 < (int)neg.size(); i += 2)
        {
            res *= (neg[i] * neg[i + 1]);
            used = true;
        }
        if (!used) 
        {
           
            if (zeros > 0) 
            {
                cout << 0 << '\n'; 
            }
            else 
            {
               
                cout << neg.back() << '\n';
            }
        }
        else 
        {
            cout << res << '\n';
        }
	}
}