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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));
    for (ll i = 0; i <= a[0]; i++)
        dp[0][i] = 1;
    for (ll i = 1; i < n; i++)
    {
        vector<ll> pf(dp[i - 1].begin(), dp[i - 1].end());
        for (ll j = 1; j <= k; j++)
            pf[j] = (pf[j - 1] + pf[j]) % mod;

        for (ll j = 0; j <= k; j++)
        {
            if (j - a[i] - 1 >= 0)
                dp[i][j] = (pf[j] - pf[j - a[i] - 1] + mod) % mod;
            else
                dp[i][j] = pf[j];
        }
    }
    cout << dp[n - 1][k] << nl;
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