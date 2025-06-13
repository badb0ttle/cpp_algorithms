/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
/*
问题描述
Alice在银行存了a元钱，定期b年，每年的利息是c%。年利息计算时会只保留到分（0.01元），分以下的利息会被舍去（注意不是四舍五入，是舍弃），年利息会累加到本金中。问最终Alice的账户里有多少钱？

例如Alice存了1000元，2年，年利息是10%，那么第1年的年利息是1000*10%=100元，加入到本金，本金变为1000+100=1100元，第二年的年利息是1100*10%=110元，本金变为1100+110=1210元。

例如Alice存了9元，2年，年利息是1%，那么第1年的年利息是9*1%=0.09元，加入到本金，本金变为9+0.09=9.09元，第二年的年利息是9.09*1%=0.0909元，保留到分，为0.09元，本金变为9.09+0.09=9.18元。

输入描述
 这是一道多组案例的题目。一个正整数n，表示案例的数量。（n<=1000）

每组案例由三个正整数a、b、c组成。（a<=1e5，b<=100，c<=10）*/
void work()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a * 100;
    for (int i = 0; i < b; ++i)
    {
        int add = (ans * c) / 100;
        ans += add;
    }
    int x = ans / 100;
    int y = ans % 100;
    cout << x;
    if (y > 0)
    {
        cout << '.';
        if (y % 10 == 0)
            cout << y / 10;
        else
            cout << y;
    }
    cout << '\n';
}
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int _ = 1;
    cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}