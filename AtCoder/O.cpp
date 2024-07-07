/*
Author: Sahil Anand
Find me on: https://linktr.ee/sahilanand30
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define nl endl
/*-------------------------{Main Code}-------------------------*/

ll rec(ll i, ll mask, vector<vector<ll>> &v, vector<vector<ll>> &dp)
{
    if (i < 0)
        return 1;
    if (dp[i][mask] != -1)
        return dp[i][mask];

    ll ans = 0;
    for (ll woman : v[i])
        if ((mask & (1LL << woman)) == 0)
            ans = (ans + rec(i - 1, (mask | (1LL << woman)), v, dp)) % mod;
    return dp[i][mask] = ans;
}
void solve()
{
    ll n, a;
    cin >> n;
    map<ll, vector<ll>> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a;
            if (a)
                m[i].push_back(j);
        }
    }
    vector<vector<ll>> v;
    for (auto val : m)
        v.push_back(val.second);
    vector<vector<ll>> dp((ll)v.size(), vector<ll>((1 << n), -1));
    if (v.empty())
    {
        cout << "0\n";
        return;
    }
    cout << rec(v.size() - 1, 0, v, dp) << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}