    /*blank*/
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long // 一时偷懒不收敛，乱开ll终遭谴
    #define sc scanf
    #define pr printf
    int a[19][26];
    int x[26];
    string s[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                    "seventeen", "eighteen", "nineteen"};
    string str;
    void work()
    {
        memset(x, 0, sizeof x);
        cin>>str;
        for(char i:str)x[i-'a']++;
        int ans=0;
        for(int i=0;i<19;++i)
        {
            bool f=1;
            for(int j=0;j<26;++j)
            {
                if(a[i][j]>0&&x[j]==0)
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int _ = 1;
        cin >> _;
        for(int i=0;i<19;++i)
        {
            for(char j:s[i])
            {
                a[i][j-'a']++;
            }
        }




        // sc("%d",&_);
        while (_--)
            work();
        return 0;
    }