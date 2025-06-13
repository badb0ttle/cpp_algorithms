/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int n,c;
    cin>>n>>c;
    int a[n];
    int cnt=0;
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int>mp;
    sort(a,a+n);
    for(int i=0;i<n;++i)mp[a[i]]++;
    for(int i=0;i<n;++i)
    {
        int idx=lower_bound(a,a+n,a[i]+c)-a;
        if(idx<n&&a[idx]==a[i]+c&&idx!=i)cnt+=mp[a[idx]];
    }
    cout<<cnt;
}
signed main()
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