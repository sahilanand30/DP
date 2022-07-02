//Author: Sahil Anand
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_h
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
ll func(ll i, ll j, ll n, ll m, vector<vector<char>>&a,vector<vll>&dp){
    if(i==n-1 && j==m-1)return 1;
    if(i>=n || j>=m)return 0;
    if(a[i][j]=='#')return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ways=0;
    //we have only 2 choices
 
    //go down
    ll w1 = func(i+1,j,n,m,a,dp);
 
    //go right
    ll w2 = func(i,j+1,n,m,a,dp);
 
    ways=(w1+w2)%mod;
    return dp[i][j]=ways;
}
int main()
{
    FASTIO
    ll n,m;
    cin>>n>>m;
    vector<vector<char>>a(n,vector<char>(m));
    vector<vll>dp(n+1,vll(m+1,-1));
    rep(i,n){
        rep(j,m)cin>>a[i][j];
    }
    ll ans=func(0,0,n,m,a,dp);
    cout<<ans<<nl;
    return 0;
}