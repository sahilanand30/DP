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
ll dfs(ll v, map<ll, vector<ll>> &g, vector<ll> &dp)
{
    if (dp[v] != -1)
        return dp[v];
    ll ans = 0;
    for (ll child : g[v])
        ans = max(ans, 1 + dfs(child, g, dp));
    return dp[v] = ans;
}
void solve()
{
    ll n, m, u, v, ans = 0;
    cin >> n >> m;
    vector<ll> dp(n + 1, -1);
    map<ll, vector<ll>> g;
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (ll i = 1; i <= n; i++)
    {
        ll res = dfs(i, g, dp);
        ans = max(ans, res);
    }
    cout << ans << nl;
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