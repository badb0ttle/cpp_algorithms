/*blank*/
#include <bits/stdc++.h>
using namespace std;
// #define int long long // 十年OI一场空，不开LL见祖宗
#define sc scanf
#define pr printf
const int mx = 1e3 + 1;
int n, m, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<string> mp;
vector<vector<int>> idx;
vector<int> v;
void bfs(int x, int y, int a)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    idx[x][y] = a;
    int n = 0;
    while (!q.empty())
    {
        auto [X, Y] = q.front();
        q.pop();
        n++;
        for (int i = 0; i < 4; i++)
        {
            int ex = X + dx[i], ey = Y + dy[i];
            if (ex >= 0 && ex < n && ey >= 0 && ey < m && mp[ex][ey] == '.' && !idx[ex][ey])
            {
                idx[ex][ey] = a;
                q.push({ex, ey});
            }
        }
    }
    v[a] = n;
}

void work()
{
    cin >> n >> m;
    mp.resize(n);
    idx.assign(n, vector<int>(m, 0));
    v.resize(n * m, 0);
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '.' && !idx[i][j])
            {
                bfs(i, j, cnt++);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j)
                cout << ' ';
            if (mp[i][j] == '.')
            {
                cout << v[idx[i][j]];
            }
            else
            {
                int sum = 1;
                int st[4] = {0}, cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int ex = i + dx[k], ej = j + dy[k];
                    if (ex >= 0 && ex < n && ej >= 0 && ej < m && mp[ex][ej] == '.')
                    {
                        int cur = idx[ex][ej];
                        bool f = 0;
                        for (int l = 0; l < cnt; l++)
                        {
                            if (st[l] == cur)
                            {
                                f = 1;
                                break;
                            }
                        }
                        if (!f)
                        {
                            st[cnt++] = cur;
                            sum += v[cur];
                        }
                    }
                }
                cout<<sum;
            }
        }
        cout << '\n';
    }
}

signed main()
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