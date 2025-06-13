/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
int n, tmp;
int a1, a2;
void work()
{
    a1=0,a2=0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        if (tmp == 1)
            a1++;
        else
            a2++;
    }
    if(a1&1)
    {
        cout<<"NO\n";
    }
    else if(a1==0&&(a2&1))
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
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