/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
ll a,b,cnt;
void work()
{
    cin>>a>>b;
    if(a>b)swap(a,b);
    while(1)
    {
        int tmp=b/a;
        cnt+=tmp;
        if(b%a==0)break;
        b-=tmp*a;
        if(a>b)swap(a,b);
    }
    cout<<cnt<<'\n';
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