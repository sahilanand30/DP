// Jay Maa Chamunda
/*
Author: Sahil Anand
Find Me on: https://linktr.ee/sahilanand30
*/
/*-----------------------------{HEADERS}-----------------------------*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/*--------------------------{Optimizations}--------------------------*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
/*------------------------------{MACROS}------------------------------*/
#define ll long long int
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
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
#define maxHeap priority_queue<ll>                   // maxElement at the top
#define minHeap priority_queue<ll, vll, greater<ll>> // minElement at the top
#define printWithPrecision(i, x) cout << fixed << setprecision(i) << x << nl
/*----------------------------{PBDS/ORDERED_SET}----------------------------*/
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*----------------------------{NON-STANDARD I/O}----------------------------*/
#define not_standard                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
/*-------------------------------{FAST I/O}-------------------------------*/
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
/*--------------------------------{MAIN CODE}--------------------------------*/
ll dp[100001][101];
ll rec(ll i, ll last, ll n, ll m, vll &a)
{
    if (i >= n)
        return 1;
    if (i > 0 && abs(a[i] - last) > 1 && a[i] > 0)
        return 0;
    if (dp[i][last] != -1)
        return dp[i][last];
    ll ans = 0;
    if (a[i] > 0)
        ans = rec(i + 1, a[i], n, m, a);
    else
    {
        if (last == 0)
        {
            for (ll val = 1; val <= m; val++)
                ans = (ans + rec(i + 1, val, n, m, a)) % mod;
        }
        else
        {
            if (last + 1 <= m)
                ans = (ans + rec(i + 1, last + 1, n, m, a)) % mod;
            if (last - 1 >= 1)
                ans = (ans + rec(i + 1, last - 1, n, m, a)) % mod;
            ans = (ans + rec(i + 1, last, n, m, a)) % mod;
        }
    }
    return dp[i][last] = ans;
}
int main()
{
    FASTIO
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        ll n, m;
        cin >> n >> m;
        vll a(n);
        rep(i, n) cin >> a[i];
        cout << rec(0, 0, n, m, a) << nl;
    }
    return 0;
}