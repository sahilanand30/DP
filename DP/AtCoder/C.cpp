//Author: Sahil Anand
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_c
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
ll dp[3][100005];
ll func(ll index, ll last, vll &a, vll &b, vll &c)
{
    if (index < 0) // base condition
    {
        return 0;
    }
    if(dp[last][index]!=-1)return dp[last][index];
    ll sumA = 0, sumB = 0, mx = 0;
    if (last == 0) // choose b or c
    {
        sumA += b[index] + func(index - 1, 1, a, b, c);
        sumB += c[index] + func(index - 1, 2, a, b, c);
    }
    else if (last == 1) // choose a or c
    {
        sumA += a[index] + func(index - 1, 0, a, b, c);
        sumB += c[index] + func(index - 1, 2, a, b, c);
    }
    else // choose a or b
    {
        sumA += a[index] + func(index - 1, 0, a, b, c);
        sumB += b[index] + func(index - 1, 1, a, b, c);
    }
    mx = max(sumA, sumB);
    return dp[last][index] = mx;
}
int main()
{
    FASTIO
    ll t = 1;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        ll n, mx = 0;
        cin >> n;
        vll a(n), b(n), c(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        if (n == 1)
        {
            mx = max(a[0], max(b[0], c[0]));
        }
        else
        {
            // func() will return the maximum sum that we want upto 'index'
            // last -> 0=a , 1=b , 2=c
            ll index = n - 1, last = 0;
            ll mx1 = a[index] + func(index - 1, last, a, b, c);
            last = 1;
            ll mx2 = b[index] + max(mx, func(index - 1, last, a, b, c));
            last = 2;
            ll mx3 = c[index] + max(mx, func(index - 1, last, a, b, c));
            mx = max(mx1, max(mx2, mx3));
        }
        cout << mx << nl;
    }
    return 0;
}