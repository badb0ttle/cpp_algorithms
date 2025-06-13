/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define pair <int, int> PII
#define debug(x) cout << #x << '=' << x << '\n'
int n;
int res;
int dfs(int n,int y)
{
    if(n==y)return 1;
    for(int i=y;i<=n;++i)
    {
        if(n%i==0)
        {
            if(n/i>=i)
            res+=dfs(n/i,i);
        }
    }
    return res;
}
void work()
{
    cin >> n;
    cout << dfs(n,2)<< '\n';
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