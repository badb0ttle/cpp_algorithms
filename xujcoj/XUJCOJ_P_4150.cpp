/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
string f(string&s)
{
    int cnt=0;int idx=-1;
    int l=0,r=s.size()-1;
    if(s.size()==1)return "a";
    string fs=s;
    reverse(fs.begin(),fs.end());
    if(fs==s)
    {
        bool ff=0;
        while(l<r)
        {
            if(s[l]!='a')
            {
                s[l]=s[r]='a';  
                ff=1;
                break;
            }
            l++;
            r--;
        }
        if(!ff&&s.size()&1)s[s.size()/2]='a';
        return s;
    }
    else
    {
    while(l<r)
    {
        if(s[l]!=s[r])
        {
            s[l]=s[r]=min(s[l],s[r]);
            idx=l;
            cnt++;
        }
        l++;
        r--;
    }
    // cout<<idx<<'\n';
    if(cnt<=1)
    {
        if((s[idx]=='a'||s[s.size()-1-idx]=='a'))
        {
            s[idx]='a',s[s.size()-1-idx]='a';
            if(s.size()&1)s[s.size()/2]='a';
        }
        else{
            s[s.size()-1-idx]='a';
            s[idx]='a';
        }
    }
    return s;
}
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