/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = LLONG_MAX;
    bool f=3*a>2*b;
    if(f)
    {
        ans=n/6*2*b;
        n%=6;
        if(n==1)ans+=min({a-b+a,a,b});
        else if(n==2)ans+=min({a,b,a+a+a-b});
        else if(n==3)ans+=min({b,a+a,a-b+a+a});
        else if(n==4)ans+=min({b+a,a+a,b+b});
        else if(n==5)ans+=min({b+a,a+a+a,b+b});
    }
    else
    {
        ans=n/6*3*a;
        n%=6;
        if(n==1)ans+=min({a,b,b-a});
        else if(n==2)ans+=min({a,b,a-b+a});
        else if(n==3)ans+=min({a+a,b,a+a+a-b});
        else if(n==4)ans+=min({a+a,b+b,a+b});
        else if(n==5)ans+=min({a+a+a,a+b,b+b});
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}