/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
int tmp, l;
void work()
{
    int n;
    cin >> n;
    int tt=INT_MIN;
    bool f=1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        if(tmp>=tt)tt=tmp;
        else 
        {
            f=0;
        }
    }
    if(f)
    cout << "Yes\n";
    else cout<<"No\n";
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