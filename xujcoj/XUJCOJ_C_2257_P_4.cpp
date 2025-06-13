/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
string s;
int len;
void work()
{
    cin>>s;
    len=s.length();
    for(int i=1;i<=len;++i)
    {
        bool f=0;
        string str=s.substr(0,i);
        int idx=0;
        while(1)
        {
            if(idx+i>len-1)break;
            if(s.substr(idx+i,i)!=str)
            {
                f=1;
                break;
            }
            else
            {
                idx+=i;
            }
        }
        if(!f)
        {
            cout<<len/i<<'\n';
            return;
        }
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