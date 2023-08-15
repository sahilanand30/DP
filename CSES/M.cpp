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
/*------------------------------{INLINE MACROS}------------------------------*/
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
ll dp[5001][5001][2];
ll rec(ll i, ll j, ll turn, vll &a){
    if(i>j)return 0;
    if(dp[i][j][turn]!=-1)return dp[i][j][turn];
    ll op1,op2,ans;
    if(turn==0){
        op1 = a[i]+rec(i+1,j,1,a);
        op2 = a[j]+rec(i,j-1,1,a);
        ans=max(op1,op2);
    }
    else{
        op1 = rec(i+1,j,0,a);
        op2 = rec(i,j-1,0,a);
        ans=min(op1,op2);
    }
    return  dp[i][j][turn]=ans;
}
int main()
{
    FASTIO
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        memset(dp,-1,sizeof(dp));
        ll n;
        cin>>n;
        vll a(n);
        rep(i,n)cin>>a[i];
        cout<<rec(0,n-1,0,a)<<nl;
    }
    return 0;
}
