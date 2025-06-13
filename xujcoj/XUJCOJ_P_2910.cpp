/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'

void work()
{
    int a[4];
    for(int&i:a)cin>>i;
    sort(a,a+4);
    if(a[0]+a[1]>abs(a[2]-a[3]))cout<<"Yes\n";
    else cout<<"No\n";
        
}
int main()
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