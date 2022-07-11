// Author: Sahil Anand
// Problem Link: https://cses.fi/problemset/task/1097
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
ll func(ll i, ll j, vll &a, vector<vll> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return a[i];
    if (i + 1 == j)
        return max(a[i], a[j]);
    if (dp[i][j] != -1)
        return dp[i][j];

    // The player have only 2 options
    // Option-1: pick ith element
    // Option-2: pick jth element

    ll ans, op1 = 0, op2 = 0;

    op1 = a[i] + min(func(i + 2, j, a, dp), func(i + 1, j - 1, a, dp)); 
    op2 = a[j] + min(func(i + 1, j - 1, a, dp), func(i, j - 2, a, dp));
    ans=max(op1,op2);
    return dp[i][j] = ans;
}
int main()
{
    FASTIO
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    vector<vll> dp(n + 1, vll(n + 1, -1));
    ll ans = func(0, n - 1, a, dp);
    cout << ans << nl;
    return 0;
}
/*
Logic:-
->Suppose we have numbers {i,i+1,........,j-1,j}
->Every player wants to maximize their score
->Hence, the opponent will also try to minimize the player's score
->Now the the player has 2 options, either select ith element or select
  jth element
->If the player chooses the ith element then opponent
  will have to choose from [i+1,..........,j]
  then player will get minimized [i+1,....,j]
->If the player chooses the jth element then the opponent will
  left with [i,i+1,..........,j-1] numbers.
  Surely opponent will try to maximize [i,j-1] for himself.
  In order to do so the player will get minimizes [i,j-1].
->
*/