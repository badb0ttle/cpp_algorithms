/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
bool cmp(int x1,int y1,int x2,int y2)
{
    if(x1+y1!=x2+y2)
    {
        return x1+y1<x2+y2;
    }
    return y1>y2;
}
int whichline(int x,int y)
{
    return x+y;
}
void work()
{
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(!cmp(x1,y1,x2,y2))
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    long double ans=0;
    int a=whichline(x1,y1);
    int b=whichline(x2,y2);
    int cnt=0;
    for(int i=a+1;i<b;++i)   cnt+=i;
    for(int i=a;i<b;++i)   ans+=sqrt((i*i)+((i+1)*(i+1)));
    if(a!=b)cnt+=y1+b-y2;
    else cnt+=abs(y1-y2);
    ans+=sqrt(2)*cnt;
    cout<<fixed << setprecision(20)<<ans<<'\n';
}
signed main()
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