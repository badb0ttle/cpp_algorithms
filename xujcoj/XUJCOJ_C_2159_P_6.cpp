/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年OI一场空，不开LL见祖宗
#define sc scanf
#define pr printf
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> idx;
vector<string> mp;
unordered_map<int, int> v;
void bfs(int x, int y, int a)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    idx[x][y] = a;
    int n = 0;
    while (!q.empty())
    {
        pair<int, int> front = q.front();
int X = front.first, Y = front.second;
        q.pop();
        n++;
        for (int i = 0; i < 4; i++)
        {
            int ex = X + dx[i], ey = Y + dy[i];
            if (ex >= 0 && ex < n && ey >= 0 && ey < m && mp[ex][ey] == '.' && idx[ex][ey] == -1)
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
    idx.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        cin >> mp[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '.' && idx[i][j] == -1)
            {
                bfs(i, j, cnt++);
            }
        }
    }
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '.')
            {
                ans[i][j] = v[idx[i][j]];
            }
            else
            {
                set<int> st;
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && mp[ni][nj] == '.')
                    {
                        st.insert(idx[ni][nj]);
                    }
                }
                int wall = 1;
                for (int i : st)
                    wall += v[i];
                ans[i][j] = wall;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
            if (j != m - 1)
                cout << " ";
        }
        cout << "\n";
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