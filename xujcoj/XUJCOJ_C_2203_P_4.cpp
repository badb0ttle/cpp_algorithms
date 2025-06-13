/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
int n;
void work()
{
    cin >> n;
    unordered_map<string, unordered_set<int>> mp;
    unordered_map<string, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        string s;
        int k;
        cin >> s >> k;

        mp[s].clear();
        cnt[s] = 0;

        for (int j = 0; j < k; ++j)
        {
            int tmp;
            cin >> tmp;
            mp[s].insert(tmp);
            cnt[s]++;
        }
    }
    vector<pair<string, int>> v;
    for (auto &[s, t] : mp)
    {
        int len = t.size();
        double avg = (double)cnt[s] / len;
        v.emplace_back(s, len);
    }

    sort(v.begin(), v.end(), [&](const auto &a, const auto &b)
         {
             if (a.second != b.second)
                 return a.second > b.second;                                          
             return (double)cnt[a.first] / a.second < (double)cnt[b.first] / b.second;
         });

    for (int i = 0; i < 3; ++i)
    {
        if(i)cout<<' ';
        if (i < v.size())
            cout << v[i].first ;
        else
            cout << "-";
    }
    cout << "\n";
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