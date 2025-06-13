/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
int m,a,b,c,mx,tmp;
void work()
{
    cin>>m;
    tmp=0;
    mx=0;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        if(a<10||b<10||c<10)tmp++;
        else{
            mx=max(mx,tmp);
            tmp=0;
        }
    }
    if(tmp)mx=max(mx,tmp);
    cout<<mx<<'\n';
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