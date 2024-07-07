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

ll dfs(ll v, ll pColor, ll p, map<ll, vector<ll>> &g, vector<vector<ll>> &dp)
{
    if (dp[v][pColor] != -1)
        return dp[v][pColor];
    ll ways = 1;
    for (ll child : g[v])
    {
        if (child != p)
        {
            if (pColor == 0)
                ways = (ways * ((dfs(child, 0, v, g, dp) + dfs(child, 1, v, g, dp)) % mod)) % mod;
            else
                ways = (ways * dfs(child, 0, v, g, dp)) % mod;
        }
    }
    return dp[v][pColor] = ways;
}
void solve()
{
    ll n, u, v;
    cin >> n;
    map<ll, vector<ll>> g;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    cout << (dfs(0, 0, -1, g, dp)+dfs(0, 1, -1, g, dp))%mod << nl;
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
