/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 21;
int n, m;
char mp[mx][mx];
bool vis[mx][mx];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int ans=1, bx, by;
struct p
{
    int x,y;
};
void bfs()
{
    queue<p>q;
    q.push({bx,by});
    vis[bx][by]=1;
    while(!q.empty())
    {  
        p t=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int ex=t.x+dx[i];
            int ey=t.y+dy[i];
            if(!vis[ex][ey]&&ex>=1&&ey>=1&&ex<=n&&ey<=m&&mp[ex][ey]!='#')
            {
                q.push({ex,ey});
                vis[ex][ey]=1;
                ans++;
            }
        }
    }
}
void work()
{
    cin >> m>> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '!')
            {
                bx = i;
                by = j;
            }
            if(mp[i][j]=='#')
            {
                vis[i][j]=1;
            }
        }
    }
    bfs();
    cout<<ans<<'\n';
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