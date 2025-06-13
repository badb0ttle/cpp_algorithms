#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
ll l[1000005],r[1000005];
ll ans = 0;
int main()
{
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i)
    {
        int st = i;
        if(a[i]==a[i+1])
        {
            int ed = i;
            while(a[ed] == a[st]) ed ++;
            ed = ed - 1;
            for(int j=st;j<=ed;j++) l[j]=st,r[j]=ed;
            i = ed;
        }
        else l[i]=i,r[i]=i;
    }
    for(ll i=1;i<=n;++i)
    {
        ll le = i - 1;
        ll ri = max(i,r[i]);
        while(le > 0)
        {
            if(a[le] == a[i])
            {
                break;
            }
            if(a[le] % a[i] == 0) le = l[le] - 1;
            else break;
        }
        if(a[i] == 1) ri = n + 1;
        else
        {
            while(ri <= n)
            {
                if(a[ri] % a[i] == 0) ri = r[ri] + 1;
                else break;
            }
        }
        le += 1;
        ri -= 1;
        //cout<<le<<' '<<ri<<' '<<(i - le + 1) * (ri - i + 1)<<'\n';
        ans += (i - le + 1) * (ri - i + 1);
    }
    printf("%lld",ans);
    //for(int i=1;i<=n;++i) cout<<l[i]<<' '<<r[i]<<'\n';
    return 0;
}