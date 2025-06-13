/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_leap(int y)
{
    return y%4==0&&y%100!=0||y%400==0&&y%3200!=0;
}
void work()
{
    int y,m,d,h,n,s;
    cin>>y>>m>>d>>h>>n>>s;
    if(is_leap(y))
    {
        month[2]=29;
    }
    else{
        month[2]=28;
    }
    if(s==60)
    {
        s=0;
        n++;
    }
    if(n==60)
    {
        n=0;
        h++;
    }
    if(h==24)
    {
        h=0;
        d++;
    }
    if(d>month[m])
    {
        d=1;
        m++;
    }
    if(m>12)
    {
        m=1;
        y++;
    }
    cout<<y<<"-"<<m<<"-"<<d<<" "<<h<<":"<<n<<":"<<s<<'\n';
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