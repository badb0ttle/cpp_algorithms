/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
struct node
{
    string s1, s2, s3;
} q[3];
void work()
{
    for (int i = 0; i < 3; ++i)
    {
        cin >> q[i].s1 >> q[i].s2 >> q[i].s3;
    }
    for (char i = 'A'; i <= 'L'; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            bool f = 0;
            for (int k = 0; k < 3; ++k)
            {
                int suma = 0, sumb = 0;
                for (char c : q[k].s1)
                {
                    suma += (c == i ? (j == 1 ? 1 : 3) : 2);
                }
                for (char c : q[k].s2)
                {
                    sumb += (c == i ? (j == 1 ? 1 : 3) : 2);
                }
                if (suma < sumb && q[k].s3 != "DOWN")
                    {f = 1;break;}
                if (suma > sumb && q[k].s3 != "UP")
                    {f = 1;break;}
                if (suma == sumb && q[k].s3 != "EVEN")
                    {f = 1;break;}
            }
            if (!f)
            {
                cout << i << " is fake and it is " << (j == 1 ? "light." : "heavy.");
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
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}