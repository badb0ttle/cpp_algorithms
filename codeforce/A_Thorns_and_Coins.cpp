/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
int n;
std::string s;
int dp[51];
void work()
{

    std::cin >> n;
    memset(dp,-1,sizeof(dp));
    std::cin>>s;
    dp[1]=0,dp[0]=0;
    for(int i=1;i<n;++i)
    {
        if(s[i]=='*'&&s[i-1]=='*')break;
        else if(s[i]=='*')continue;
        if(i-1>=0&&dp[i-1]!=-1)dp[i]=std::max(dp[i-1],dp[i]);
        if(i-2>=0&&dp[i-2]!=-1)dp[i]=std::max(dp[i-2],dp[i]);
        if(dp[i] != -1 && s[i]=='@')dp[i]++;
    }
    std::cout<<*std::max_element(dp+1,dp+1+n)<<'\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_--)
        work();
    return 0;
}