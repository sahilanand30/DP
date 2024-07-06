/*
Author: Sahil Anand
Find me on: https://linktr.ee/sahilanand30
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define nl endl
/*-------------------------{Main Code}-------------------------*/
bool rec(ll k, ll turn, vector<ll>&a, vector<vector<ll>>&dp){
    bool unable=true, ans=false;
    if(dp[k][turn]!=-1)return dp[k][turn];
    if(turn==0){
        for(ll x : a){
            if(x<=k){
                unable=false;
                ans|=rec(k-x,1,a,dp);
            }
        }
        if(unable)ans=false;
    }
    else{
        ans=true;
        for(ll x : a){
            if(x<=k){
                unable=false;
                ans&=rec(k-x,0,a,dp);
            }
        }
        if(unable)ans=true;
    }
    return dp[k][turn] = ans;
}
void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    vector<vector<ll>>dp(k+1,vector<ll>(2,-1));
    for(ll i=0;i<n;i++)cin>>a[i];
    if(rec(k,0,a,dp))cout<<"First\n";
    else cout<<"Second\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
