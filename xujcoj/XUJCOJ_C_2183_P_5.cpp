/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
/*
问题描述
有一个数列，前3项是a、b、c，从第4项开始，如果是第3m+1项（例如第4、7、10项），该项是前三项之和的末三位数；如果是第3m+2项（例如第5、8、11项），该项是前两项的最大公因数；如果是第3m项（例如第6、9、12项），该项是前三项乘积的末三位数。

规定：如果两个数中至少有一个是0，则它们的最大公因数是另一个数。例如0和5的最大公因数是5，0和0的最大公因数是0。

输入描述
这是一道多组案例的题目。一个正整数n，表示案例的数量。（n<=1000）

每组案例由4个整数a、b、c、x组成。（0<=a,b,c<=999，1<=x<=300000）*/
const int mx = 3e5 + 1;
int a, b, c, x;
struct p
{
    int a, b, c, op;
    bool operator<(const p &ot) const
    {
        if (a != ot.a)
            return a < ot.a;
        if (b != ot.b)
            return b < ot.b;
        if (c != ot.c)
            return c < ot.c;
        return op < ot.op;
    }
};
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
void work()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    map<p, int> vis;
    vector<int> v = {a, b, c};
    int n = -1;
    for (int i = 4; i <= x; ++i)
    {
        int tmp;
        if (i % 3 == 1)
            tmp = (a + b + c) % 1000;
        else if (i % 3 == 2)
            tmp = gcd(b, c) ? gcd(b, c) : max(b, c);
        else
            tmp = (a * b * c) % 1000;
        a = b;
        b = c;
        c = tmp;
        p pi = {a, b, c, i % 3};
        if (vis.count(pi))
        {
            n = vis[pi];
            break;
        }
        vis[pi] = v.size();
        v.push_back(tmp);
    }

    if (n != -1)
    {
        if (x - 1 < n)
        {
            cout << v[x - 1] << '\n';
        }
        else
        {
            int len = v.size() - n;
            int idx = (x - 1 - n) % len + n;
            cout << v[idx] << '\n';
        }
    }
    else
    {
        cout << v[v.size() - 1] << '\n';
    }
}

signed main()
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