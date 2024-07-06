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
ll calc(ll l, ll r, ll i, vector<ll> &a)
{
    ll left, right = a[r];
    if (i - 1 >= 0)
    {
        left = a[i - 1];
        right -= a[i - 1];
    }
    if (l - 1 >= 0)
        left -= a[l - 1];
    return (left + right);
}
ll rec(ll l, ll r, vector<ll> &a, vector<vector<ll>> &dp)
{
    if (l >= r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    ll ans = 1e15;
    for (ll i = l + 1; i <= r; i++)
        ans = min(ans, calc(l, r, i, a) + rec(l, i - 1, a, dp) + rec(i, r, a, dp));
    return dp[l][r] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 1; i < n; i++)
        a[i] += a[i - 1];
    cout << rec(0, n - 1, a, dp) << nl;
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