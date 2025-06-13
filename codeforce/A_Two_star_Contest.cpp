/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
struct node
{
    ll t,sum;
    vector<ll> a;
    bool operator<(const node &ot) const
    {
        return t==ot.t?(sum<ot.sum?1:0):0;
    }
};
vector<node> s;
ll sum, n, m, k,lmx,lmn;

void work()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        vector<ll> vec(m);
        sum = 0;
        for (ll &i : vec)
        {
            cin >> i;
            if(i!=-1)
            sum += i;
        }
        s.push_back({t,sum, vec});
    }
    sort(begin(s),end(s));
    
    for(auto i:s)
    {

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}