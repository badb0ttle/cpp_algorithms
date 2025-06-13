/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
ll n,tmp;
string s;
void work()
{
    cin >> n;
    ll mxr = -1, ans = -1;
    for (int i = 1; i <= n; ++i)
    {   
        cin >> tmp;
        s = to_string(tmp);
        reverse(begin(s), end(s));
        ll re = stoll(s);
        if (re > mxr || (re == mxr && tmp > ans))
        {
            mxr = re;
            ans = tmp;
        }
    }
    cout << ans << '\n';
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}