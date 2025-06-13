/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 101;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
char mp[101][101], tmp[101][101];
int a, b, m;
string s;
void work()
{
    cin >> a >> b;
    for (int i = 1; i <= a; ++i)
    {
        cin >> s;
        for (int j = 1; j <= b; ++j)
            mp[i][j] = s[j - 1]; // 不减 '0'，直接存 char
    }

    cin >> m;
    while (m--)
    {
        for (int i = 1; i <= a; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                int h = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int ex = i + dx[k], ey = j + dy[k];
                    if (ex >= 1 && ex <= a && ey >= 1 && ey <= b)
                        h += (mp[ex][ey] == '1');
                }

                if (mp[i][j] == '1')
                {
                    if (h == 2 || h == 3)
                        tmp[i][j] = '1';
                    else
                        tmp[i][j] = '0';
                }
                else
                {
                    if (h == 3)
                        tmp[i][j] = '1';
                    else
                        tmp[i][j] = '0';
                }
            }
        }

        for (int i = 1; i <= a; ++i)
            for (int j = 1; j <= b; ++j)
                mp[i][j] = tmp[i][j];
    }

    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
            cout << mp[i][j];
        cout << '\n';
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