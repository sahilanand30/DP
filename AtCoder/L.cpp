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
ll rec(ll i, ll j, ll turn, vector<ll> &a, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j][turn] != -1)
        return dp[i][j][turn];

    ll op1 = 0, op2 = 0, ans;
    if (turn == 0)
    {
        op1 = a[i] + rec(i + 1, j, 1, a, dp);
        op2 = a[j] + rec(i, j - 1, 1, a, dp);
        ans = max(op1, op2);
    }
    else
    {
        op1 = rec(i + 1, j, 0, a, dp);
        op2 = rec(i, j - 1, 0, a, dp);
        ans = min(op1, op2);
    }
    return dp[i][j][turn] = ans;
}
void solve()
{
    ll n, s = 0;
    cin >> n;
    vector<ll> a(n);
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    ll x = rec(0, n - 1, 0, a, dp);
    ll y = s - x;
    cout << x - y << nl;
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