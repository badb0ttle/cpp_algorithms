/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx = 1e4 + 1;
int n, m,  x, y,q;
struct rec
{
    int x1, y1, x2, y2;
};
void work()
{
    cin >> n >> m >> q;
    vector<rec> v;
    vector<rec> tmp;    
    v.push_back({1, 1, n, m});
    while(q--)
    {
        cin >> x >> y;
        tmp.clear();
        for (int i=0;i<v.size();++i)
        {
            if (v[i].x1 <= x && v[i].x2 >= x && v[i].y1 <= y && v[i].y2 >= y)
            {
                tmp.push_back({v[i].x1,v[i].y1,x-1,v[i].y2});
                tmp.push_back({v[i].x1,v[i].y1,v[i].x2,y-1});
                tmp.push_back({x+1,v[i].y1,v[i].x2,v[i].y2});
                tmp.push_back({v[i].x1,y+1,v[i].x2,v[i].y2});
                swap(v[i],v[v.size()-1]);
                v.pop_back();
                i--;
            }
        }
        for(auto i:tmp)v.push_back(i);
    }
    int ans = 0;
    for (auto i : v) ans = max(ans, (i.x2 - i.x1 + 1) * (i.y2 - i.y1 + 1));
    cout << ans << '\n';
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