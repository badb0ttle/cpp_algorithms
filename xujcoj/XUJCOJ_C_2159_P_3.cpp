/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    string s;
    cin>>s;
    int n=s.size();
    string ans="";
    for(int i=0;i<n;++i)
    {
        if(s[i]=='W')ans+="E";
        else if(s[i]=='E')ans+="W";
        else if(s[i]=='S')ans+="N";
        else if(s[i]=='N')ans+="S";
    }
    cout<<ans<<'\n';
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