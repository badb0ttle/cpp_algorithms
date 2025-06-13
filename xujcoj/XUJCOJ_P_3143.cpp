/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
void work()
{
    int n;
    cin >> n;
    stack<int> a, b;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            char c;
            cin >> c;
            if (c == 'a')
            {
                int x;
                cin >> x;
                a.push(x);
            }
            else
            {
                int x;
                cin >> x;
                b.push(x);
            }
        }
        else if (s == "pop")
        {
            char c;
            cin >> c;
            if (c == 'a')
            {
                if (a.empty())
                {
                    cout << "EMPTY\n";
                }
                else
                {
                    cout << a.top() << '\n';
                    a.pop();
                }
            }
            else
            {
                if (b.empty())
                {
                    cout << "EMPTY\n";
                }
                else
                {
                    cout << b.top() << '\n';
                    b.pop();
                }
            }
        }
        else
        {
            char c1, c2;
            cin >> c1 >> c2;
            if (c1 == 'a' && c2 == 'b')
            {
                stack<int> tmp;
                while (!b.empty())
                {
                    tmp.push(b.top());
                    b.pop();
                }
                while (!tmp.empty())
                {
                    a.push(tmp.top());
                    tmp.pop();
                }
            }
            else if (c1 == 'b' && c2 == 'a')
            {
                stack<int> tmp;
                while (!a.empty())
                {
                    tmp.push(a.top());
                    a.pop();
                }
                while (!tmp.empty())
                {
                    b.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }
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