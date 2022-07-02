//Author: Sahil Anand
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_i
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
long double func(ll i, ll h, ll t, vector<long double> &a, vector<vector<long double>> &dp)
{
    if (i < 0)
    {
        if (h > t)
            return 1.0;
        return 0.0;
    }
    if (dp[i][h] != -1)
        return dp[i][h];
    long double ans = 1.0;
    long double w1 = a[i] * func(i - 1, h + 1, t, a, dp);
    long double w2 = (1.0 - a[i]) * func(i - 1, h, t + 1, a, dp);
    ans = (w1 + w2);
    return dp[i][h] = ans;
}
int main()
{
    FASTIO
    ll n;
    cin >> n;
    vector<long double> a(n);
    vector<vector<long double>> dp(n + 1, vector<long double>(n + 1, -1));
    cin >> a;
    long double ans = func(n - 1, 0, 0, a, dp);
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}