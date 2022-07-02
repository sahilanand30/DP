//Author: Sahil Anand
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d
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
ll func(ll i, ll w, vll &wt, vll &val,vector<vll>&dp){
    if(i<0 || w<0)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    //We have only 2 choices
    ll value=0,v1=0,v2=0;
    //pick ith element
    if(w>=wt[i])v1=val[i]+func(i-1,w-wt[i],wt,val,dp);
 
    //skip ith element
    v2=func(i-1,w,wt,val,dp);
    return dp[i][w]=max(v1,v2);
}
int main()
{
    FASTIO
    ll n,w;
    cin>>n>>w;
    vll wt(n), val(n);
    vector<vll>dp(n+1, vll(w+1,-1));
    rep(i,n){
        cin>>wt[i]>>val[i];
    }
    ll ans=func(n-1,w,wt,val,dp);
    cout<<ans<<nl;
    return 0;
}