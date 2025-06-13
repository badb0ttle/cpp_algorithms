/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
const int mxn=1e3+1;
const int mxm=1e6+1;
int prime[mxn];
bool is_prime[mxm];
void get_prime()
{
    int cnt=0;
    for(int i=2;i<mxm;i++)
    {
        if(!is_prime[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<mxm;j++)
        {
            is_prime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void work()
{
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=0;i<mxn;++i)
    {
        for(int j=0;j<mxn;++j)
        {
            
        }
    }
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
get_prime();
//cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}