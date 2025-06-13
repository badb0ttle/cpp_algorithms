/*🫵😉👍*/
#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include<string.h>
#include<string>
#include<stdio.h>
#include<deque>
#include<numeric>
using namespace std;
#define ll long long
#define lll __uint128_t
#define ld long double
#define ull unsigned long long
#define re register
#define il inline
#define fi first
#define SZ(x) ((int)(x).size())
#define se second
#define all(v) v.begin(),v.end()
#define pb push_back
#define lowbit(x) (x&-x)
#define fixed(x) fixed<<setprecision(x)
#define lcm(x,y) x*y/__gcd(x,y)
#define endl "\n"
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll N = 21, M = 1e6+10, base = 13331, mod = 1e9 + 7;
const ull INF=1e18;
const double pie=acos(-1),eps=1e-8;
int dir[]={0,1,0,-1,0};
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,-1,0,1,-1};
typedef pair<ll, ll>PAIR;
ll dp[N][N], a,b;
void solve(){
    cin>>a>>b;
    for(int i=1;i<=a;++i)dp[i][1]=1;
    for(int i=1;i<=b;++i)dp[1][i]=1;
    for(int i=2;i<=a;++i)
    {
        for(int j=2;j<=b;++j)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[a][b]<<'\n';
}
signed main(){
    io;
    ll _ = 1;
    //cin >> _;
    while(_ -- ) solve();
    return 0;
}