/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'

int d, p;

bool isn(string f)
{
    for (char i : f)
        if (!isdigit(i))
            return 0;
    return 1;
}

struct q
{
    string name, id;
    int f, idx, tim, day;
    bool operator<(const q &b) const
    {
        return tim == b.tim ? idx < b.idx : tim < b.tim;
    }
};

map<string, int> sy;
map<string, bool> vis;
vector<q> v;
vector<q> w;

void work()
{
    cin >> d >> p;
    for (int i = 1; i <= d; ++i)
    {
        int t, s;
        cin >> t >> s;

        map<string, q> m;
        map<string, q> ff;

        for (int j = 1; j <= t; ++j)
        {
            q tmp;
            cin >> tmp.name >> tmp.id >> tmp.f;
            int h, mnt;
            scanf("%d:%d", &h, &mnt);
            tmp.tim = h * 60 + mnt;
            tmp.idx = j;
            tmp.day = i;

            if (tmp.id.size() != 18 || !isn(tmp.id))
                continue;

            if (!m.count(tmp.id) || tmp.tim < m[tmp.id].tim)
                m[tmp.id] = tmp;

            if (tmp.f == 1 && !ff.count(tmp.id))
                ff[tmp.id] = tmp;
        }

        vector<q> tq;
        for (auto &[id, rec] : m)
            tq.push_back(rec);

        sort(tq.begin(), tq.end());

        int cnt = 0;
        for (auto &rec : tq)
        {
            if (!sy.count(rec.id) || sy[rec.id] + p < i)
            {
                v.push_back(rec);
                sy[rec.id] = i;
                cnt++;
                if (cnt == s)
                    break;
            }
        }

        for (auto &[id, rec] : ff)
        {
            if (!vis.count(id))
            {
                w.push_back(rec);
                vis[id] = true;
            }
        }
    }

    for (auto &i : v)
        cout << i.name << ' ' << i.id << '\n';

    for (auto &i : w)
        cout << i.name << ' ' << i.id << '\n';
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}