/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int cnt=0;
    for(int i=30;i<=30000;++i)
    {
        int fcnt=0,num=i,f=2;
        while(num>1)
        {
            if(num%f==0)
            {
                fcnt++;
                while(num%f==0)num/=f;
            }
            f++;
        }
        if(fcnt==3)
        {
            if(cnt>0)cout<<' ';
            cnt++;
            cout<<i;
            if(cnt==10000)break;
        }
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