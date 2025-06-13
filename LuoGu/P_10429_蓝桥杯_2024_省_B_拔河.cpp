/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 501;
struct point
{
    vector<ll>x;
}g[mx];
ll v, e, k, l, r, n, tmp;
ll a[mx];
void work()
{
    cin >> v >> e >> k;
    for(int i=1;i<=e;++i)
    {
        cin>>l>>r;
        g[l].x.push_back(r);
        g[r].x.push_back(l);
    }
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        bool f=0;
        set<ll>s;
        for(int j=1;j<=v;++j)
        {
            cin>>a[j];
            s.insert(a[j]);
        }
        if(s.size()>k)
        {
            cout<<"No\n";
            continue;
        }
        for(int j=1;j<=v&&(!f);++j)
        {
            for(auto i:g[j].x)
            {
                if(a[j]==a[i])
                {
                    f=1;
                    break;
                }
            }
        }
        cout<<(!f?"Yes":"No")<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}