#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
int n, m;
void work()
{
    int mp[100005]{};
    int cnt = 0;
    map<int, int> money;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (i == 0)
        {
            for (int k = 0; k < s.size(); k++)
            {
                if (k != 0 && s[k - 1] == '0' && s[k] != '0' || k == 0 && s[k] != '0')
                {
                    cnt++;
                }
                if (s[k] != '0')
                {
                    mp[k] = cnt;
                }
            }
            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] != '0' && s[k] != '1')
                {
                    money[mp[k]]++;
                }
            }
        }
        else
        {
            for (int k = 0; k < s.size(); k++)
            {
                if (k != 0 && s[k - 1] == '0' && !mp[k] && s[k] != '0' || k == 0 && s[k] != '0' && !mp[k])
                {
                    cnt++;
                }
                if (s[k] != '0')
                {

                    if (mp[k])
                    {
                        int t = k;
                        while (t >= 0 && s[t] != '0')
                        {
                            mp[t] = mp[k];
                            t--;
                        }
                    }
                    else
                        mp[k] = cnt;

                }
                else
                {
                    mp[k]=0;
                }
            }
            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] != '0' && s[k] != '1')
                {
                    money[mp[k]]++;
                }
            }
        }
        for(int i=0;i<11;++i)
        {
            cout<<mp[i];
        }
        cout<<'\n';
    }
    
    cout << cnt << " " << money.size();
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        work();
    }
}