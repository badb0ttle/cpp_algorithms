/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int a,b,c;
    cin >> a >> b >> c;
    int A=a%10;
    int B=b%10;
    int C=c%10;
    cout<<A+B+C<<'\n';
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