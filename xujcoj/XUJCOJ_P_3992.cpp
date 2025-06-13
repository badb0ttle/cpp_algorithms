/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
int getprimecount(int n)
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans+=2;
            if(i*i==n)ans--;
        }
    }
    return ans;
}
void work()
{
    int n;
    cin >> n; 
    int tmp = n;
    
    while (tmp != 1 && tmp != 2) {
        for (int i = 0; i < tmp; ++i) {
            cout << '*';
        }
        cout << '\n';
        
        tmp = getprimecount(tmp);
    }
    for (int i = 0; i < tmp; ++i) {
        cout << '*';
    }
    cout << '\n';
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