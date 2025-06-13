/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
// 设有n个正整数，将他们连接成一排，组成一个最大的多位整数，整数不能拆分。
// 先输入n，代表有n个整数(2<=n<=10)，下一行输入这n个整数，每个整数介于1和32767之间，整数之间以空格隔开
void work()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)  cin >> a[i];

    string mx = "";
    sort(a.begin(), a.end(), [](string x, string y)
         { return x + y > y + x; });

    for (string i : a)
        mx += i;
    cout << mx << '\n';
}
signed main()
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