/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
map<int,int>mp;
void getnum(int n)
{
    while(n)
    {
        mp[n%10]++;
        n/=10;
    }
}
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        getnum(i);
    }   
    for(int i=0;i<=9;++i)
    {
        cout<<mp[i]<<'\n';
    }
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