/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx = 2e4 + 1;
void work()
{

    ll a;
    ll t = 1;
    while (cin >> a)
    {
        if (a == 0)
            break;
        ll tmp = 0;
        bool f = 0;
        int i = 0;
        for (i = 1; i <= a; ++i) { 
            tmp = (tmp * 10 + 8) % a;
            if (tmp == 0) {
                cout << "Case " << t << ": " << i << '\n';
                break;
            }
        }
        if (i > a) cout << "Case " << t << ": 0\n";
        t++;
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