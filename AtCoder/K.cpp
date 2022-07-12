// Author: Sahil Anand
// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_k
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
ll a[100001], dp[100001];
bool func(ll k, ll n)
{
    // base case
    if (k < a[0])
    {
        return false;
    }

    if (dp[k] != -1)
        return dp[k];
    bool ans = true;
    rep(i, n)
    {
        if (a[i] <= k)
        {
            ans &= func(k - a[i], n);
        }
    }
    if (ans)
        dp[k] = 0;
    else
        dp[k] = 1;

    return dp[k];
}
int main()
{
    FASTIO
    memset(dp, -1, sizeof(dp));
    ll n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    if (func(k, n))
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}
/*
Logic:-
->Its a finite game because we are given a finite no. of stones in a pile i.e 'k'.
  And also after each move our 'k' is decreasing continously.
->When we carefully observe, we can see that the player's winning or lossing state in the game is
  sololy depends upon the 'k' value which is given to him.
->We can also oberve that, when the player gets 'k' which is less than the minimum value in the
  array 'a' then the player is gonna to lose as its mentioned in the game. So that will be the
  player's lossing state.
->So, from above obeservations we can determine that no matter what the current player is choosing
  a[i] from 'a',if the opponent is getting winning state all the times then the
  current player will always lose.
->Similarly, when the current player has atleast one a[i] from which he can put opponent in the losing
  state then the current player will win for sure.
*/