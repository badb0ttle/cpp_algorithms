/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
int a,m;

ll getp(ll x) {
    ll res = 1;
    for (ll i = 2; i * i <= x; ++i) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        if (cnt % 2 == 1) res *= i;
    }
    if (x > 1) res *= x; 
    return res;
}
void work()
{
    cin >> a >> m;
    
    cout << m /getp(a)<< '\n';

}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
//cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}