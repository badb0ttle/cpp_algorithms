/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
int n,q;
map<string,set<int> >mp;
void work()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        for(int j=1;j<=tmp;++j)
        {
            string str;
            cin>>str;
            mp[str].insert(i);
        }
    }
    cin>>q;
    while(q--)
    {
        string str;
        cin>>str;
        bool f=0;
        for(auto i:mp[str])
        {
            if(!f)
            {
                cout<<i;
                f=1;
            }
            else
            cout<<' '<<i;
        }
        cout<<'\n';
    }
}
int main()
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