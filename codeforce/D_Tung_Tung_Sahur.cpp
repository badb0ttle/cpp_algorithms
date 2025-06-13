/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
string a, b;
void work()
{
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    if (m < n || m > 2 * n || a[0] != b[0])
    {
        cout << "NO\n";
        return;
    }
    vector<int> va, vb;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            va.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    va.push_back(cnt);
    cnt = 1;
    for (int i = 1; i < m; i++)
    {
        if (b[i] != b[i - 1])
        {
            vb.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    vb.push_back(cnt);
    if (va.size() != vb.size())
    {
        cout << "NO\n";
        return;
    }
    n = va.size();
    for (int i = 0; i < n; i++)
    {
        if (va[i] > vb[i] || va[i] * 2 < vb[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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