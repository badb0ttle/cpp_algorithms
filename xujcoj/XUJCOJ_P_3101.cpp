/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=1e6+7;
char a[mx],b[mx];
void work()
{
    cin>>a+1>>b+1;
    int l1=strlen(a+1),l2=strlen(b+1);
    if(l1==l2)cout<<"Both\n";
    else if(l1>l2)
    {
        for(int i=1;i<=l1;++i)cout<<a[i];
        cout<<'\n';
    }
    else
    {
        for(int i=1;i<=l2;++i)cout<<b[i];
        cout<<'\n';
    }
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