/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int,int>
#define debug(x) cout<<#x<<'='<<x<<'\n'
const int mx=801;
int n;
int a[mx][mx];
void work()
{
    cin>>n;
    set<int>st;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            st.insert(a[i][j]);
        }
    }
    vector<int>b(2*n+1,0);
    bool f=0;
    int total = 2*n * (2*n + 1) / 2;
    int sum = 0;
    for (int i : st) sum += i;
    b[1]=total-sum;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            b[i+j]=a[i][j];
        }
    }
    for(int i=1;i<=2*n;++i)
    {
        cout<<b[i]<<' ';
    }
    cout<<'\n';
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