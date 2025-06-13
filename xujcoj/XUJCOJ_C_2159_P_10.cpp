/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
const int inf = 1e9 + 7;
set<int> st;
vector<int>pre;
void Pre(int x)
{
    for (int i = 1; i <= x; i++) {
        if (st.find(i) == st.end()) {  
            pre.push_back(i);
        }
    }
}
void work()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    Pre(inf);
    while (m--)
    {
        int k;
        cin >> k;
        cout << pre[k - 1] << "\n";
         
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