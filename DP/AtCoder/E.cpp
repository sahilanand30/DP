//Author: Sahil Anand
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_e
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
ll dp[105][100005];
ll func(ll i, ll p, vll &wt, vll &price){ 
    if(p==0)return 0;
    if(i<0)return 1e15;
    if(dp[i][p]!=-1)return dp[i][p];
    ll ans=1e15;
    
    //pick ith element if possible
    if(p-price[i]>=0)ans=min(ans, func(i-1,p-price[i],wt,price)+wt[i]);
 
    //skip ith element
    ans=min(ans, func(i-1,p,wt,price));
 
    return dp[i][p]=ans;
}
int main()
{
    /*
    Here func(i,p,wt,price) defines that how much minimum weight is required to make price 'p' if we have
    elements till 'i'
    */
    FASTIO
    memset(dp,-1,sizeof(dp));
    ll n,w;
    cin>>n>>w;
    vll wt(n),price(n);
    rep(i,n){
        cin>>wt[i]>>price[i];
    }
    for(ll p=100000;p>=0;p--){
        if(func(n-1,p,wt,price)<=w){
            cout<<p<<nl;
            break;
        }
    }
    return 0;
}