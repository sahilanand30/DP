//Author: Sahil Anand
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_f
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
ll func(ll i, ll j, string &a, string &b, vector<vll> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // We have only 3 options
    int o1 = 0, o2 = 0, o3 = 0;
    o1 = func(i - 1, j, a, b, dp);
    o2 = func(i, j - 1, a, b, dp);
    o3 = func(i - 1, j - 1, a, b, dp) + (a[i] == b[j]);
 
    return dp[i][j] = max(o1, max(o2, o3));
}
int main()
{
    FASTIO
    string a, b, c;
    cin >> a >> b;
    ll n = a.length(), m = b.length();
    vector<vll> dp(n + 1, vll(m + 1, -1));
    ll ans = func(n - 1, m - 1, a, b, dp);
    // rep(i,n){
    //     rep(j,m)cout<<dp[i][j]<<' ';
    //     cout<<nl;
    // }
    ll i = n-1, j = m-1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == b[j])
        {
            c.push_back(a[i]);
            i--, j--;
        }
        else
        {
            if(i==0 && j==0){
                break;
            }
            else if(i==0){
                j--;
            }
            else if(j==0){
                i--;
            }
            else{
                if(dp[i-1][j]>=dp[i][j-1])i--;
                else j--;
            }
        }
    }
    reverse(all(c));
    cout << c << nl;
    return 0;
}