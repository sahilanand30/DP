//Author: Sahil Anand
//Problem Link: https://cses.fi/problemset/task/1745
/*-----------------------------------------------{HEADERS}-----------------------------------------------*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*------------------------------------------------{MACROS}------------------------------------------------*/
using namespace std;
using namespace __gnu_pbds;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long int
#define ull unsigned long long int
#define countSetBits(z) __builtin_popcountll(z);
#define vll vector<long long int>
#define LL_MAX __LONG_LONG_MAX__
#define LL_MIN -9223372036854775808
#define PI 3.1415926536
#define mod 1000000007
#define INF 1e18
#define nl endl
#define yes cout << "YES\n"
#define no cout << "NO\n"
/*-----------------------------------------------{FAST I/O}-----------------------------------------------*/
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
/*-------------------------------------------{NON-STANDARD I/O}-------------------------------------------*/
#define not_standard                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
/*-------------------------------------------{PBDS/ORDERED_SET}-------------------------------------------*/
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*------------------------------------------{OPERATOR_OVERLOADS}------------------------------------------*/
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
/*-----------------------------------------------{MAIN CODE}-----------------------------------------------*/

bool possible(ll i, ll tar, vll &a, vector<vll> &dp)
{
    if (tar == 0)
        return true;
    if (i < 0)
        return false;
    if (dp[i][tar] != -1)
        return dp[i][tar];
    bool ok = false;
    // we have only  2 choices
 
    // pick ith coin
    if (tar >= a[i])
        ok |= possible(i - 1, tar - a[i], a, dp);
 
    // dont pick ith coin
    ok |= possible(i - 1, tar, a, dp);
    if (ok)
        dp[i][tar] = 1;
    else
        dp[i][tar] = 0;
    return dp[i][tar];
}
int main()
{
    FASTIO
    ll n, mn = INT_MAX;
    cin >> n;
    vll a(n);
    rep(i, n)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    ll sum = accumulate(all(a), 0);
    vll ans;
    vector<vll> dp(n + 1, vll(sum + 1, -1));
    for (ll i = mn; i <= sum; i++)
    {
        if (possible(n - 1, i, a, dp))
            ans.push_back(i);
    }
    cout << ans.size() << nl << ans << nl;
    return 0;
}