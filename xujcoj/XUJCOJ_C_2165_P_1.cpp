/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int m,n;bool f=1;
    cin>>m>>n;
    if(m==n)cout<<"Stan wins\n";
    if(m<n)swap(m,n);
    if(m/n>=2)cout<<"Stan wins\n";
    else
    {
        while(m/n<2)
        {
            m-=n;
            f^=1;
            if(m<n)swap(m,n);
        }
        if(f)cout<<"Stan wins\n";
        else cout<<"Ollie wins\n";
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