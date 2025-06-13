/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
string s;
int n;
void work()
{
    cin>>n;
    cin>>s;
    for(char&i:s)
    {
        if(i=='I')i='l';
        else if(i=='l')i='I';
    }
    cout<<s<<'\n';

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