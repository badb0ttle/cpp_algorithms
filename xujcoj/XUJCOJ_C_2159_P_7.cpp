/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf

string f(string s)
{
    int n = s.size();
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            char min_char = min(s[l], s[r]);
            s[l] = s[r] = min_char;
            cnt++;
            if (cnt == 2)
                break; 
        }
        l++;
        r--;
    }
    l = 0;
    r = n - 1;
    while (cnt < 2 && l <= r)
    {
        if (s[l] == s[r])
        {
            if (s[l] > 'a')
            {
                s[l] = s[r] = 'a'; 
                cnt++;
                if (cnt == 2)
                    break;
            }
        }
        l++;
        r--;
    }
    if (n % 2 == 1 && cnt < 2)
    {
        int mid = n / 2;
        if (s[mid] > 'a')
        {
            s[mid] = 'a';
            cnt++;
        }
    }
    return s;
}

void work()
{
    string s;
    cin>>s;
    cout<<f(s)<<'\n';
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
//cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}