/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
bool isprime(int num)
{
    if (num == 1)
    {
        return false;
    }
    if (num == 2 || num == 3)
    {
        return true;
    }
    if (num % 6 != 1 && num % 6 != 5)
    {
        return false;
    }
    for (int i = 5; i <= sqrt(num); i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
void work()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int kth_max, kth_min;
    kth_max = a[n - k];
    kth_min = a[k - 1];
    int num = kth_max - kth_min;
    if(isprime(num))
        cout << "YES\n";
    else
        cout << "NO\n";
        cout<<num<<'\n';
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