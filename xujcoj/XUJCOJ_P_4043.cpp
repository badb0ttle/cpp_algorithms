/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
ll k,x,y;
void work()
{
    cin>>k>>x>>y;
    set<ll>st;
    for(int i=1;i<=sqrt(x);++i)
    {
        if(x%i==0)
        {
            st.insert(i),st.insert(x%i);
        }
    }
    for(int i=1;i<=sqrt(y);++i)
    {
        if(y%i==0)
        {
            st.insert(i),st.insert(y%i);
        }
    }
    for(auto i:st)
    {
        insert(i);
    }
    cout<<
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