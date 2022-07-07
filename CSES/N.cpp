// Author: Sahil Anand
// Problem Link: https://cses.fi/problemset/task/1093
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
ll binpow(ll a, ll b, ll M)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}
ll func(ll n, ll tar, vector<vll> &dp)
{
    if (tar == 0)
        return 1;
    if (n <= 0)
        return 0;
    if (dp[n][tar] != -1)
        return dp[n][tar];
    // We have only 2 choices
    ll ways, w1 = 0, w2 = 0;

    // pick nth element in the set-1
    if (tar >= n)
        w1 = func(n - 1, tar - n, dp);

    // dont pick nth element in the set-1
    w2 = func(n - 1, tar, dp);
    ways = (w1 + w2) % mod;
    return dp[n][tar] = ways;
}
int main()
{
    FASTIO
    ll n;
    cin >> n;
    if (((n * (n + 1)) / 2) % 2 == 0)
    {
        ll tar = ((n * (n + 1)) / 2) / 2;
        vector<vll> dp(n + 1, vll(tar + 1, -1));
        ll ans = func(n, tar, dp);
        cout << (ans * binpow(2,mod-2,mod))%mod << nl;
        /*
        Here we cannot directly divide the ans by '2' as we are performing 
        the mod operations.
        So instead of dividing ans by '2' we will multiply ans with binpow(2,mod-2,mod)
        */
    }
    else
    {
        cout << "0\n";
    }
    return 0;
}