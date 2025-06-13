/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
int n, m, l, r;

void work()
{
    int n, m, l, r;
    bool f1=0, f2=0;
    cin >> n >> m >> l >> r;
    int l1 = 0, l2 = 0;
    while (m > 0)
    {
        
        if(l1==l&&l2==r)
        {
            cout<<l1<<' '<<l2<<'\n';
            return;
        }
        else if (l1 == l)
        {
            f1 = 1;
        }
        else if(l2==r)
        {
            f2=1;
        }
        if (!f1)
        {
            l1--;
            m--;
            if (m == 0)
            {
                cout << l1 << ' ' << l2 << '\n';
                return;
            }
        }
        if (!f2)
        {
            l2++;
            m--;
            if (m == 0)
            {
                cout << l1 << ' ' << l2 << '\n';
                return;
            }
        }
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