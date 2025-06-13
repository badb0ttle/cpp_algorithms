
    /*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long           // 一时偷懒不收敛，乱开ll终遭谴
#define ull unsigned long long
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
const int mx=1e6+9;
const ull base=1771;
char s[mx];
ull h[mx],b[mx],hr[mx];
int n;
ull gh(int l,int r)
{
	return h[r]-h[l-1]*b[r-l+1];
}
ull ghr(int l,int r)
{
	return hr[l]-hr[r+1]*b[r-l+1];
}
bool check(int x)
{
	for(int i=x;i<=n;++i)  
    {
        int j=i-x+1;
        if(gh(j,i)==ghr(j,i))return 1;
    }
	return 0;
}
void work()
{
	cin>>s+1;
	n=strlen(s+1);
	b[0]=1;
    for(int i=1;i<=n;++i)
    {
    	b[i]=b[i-1]*base;
    	h[i]=h[i-1]*base+s[i]-'a'+base;
	}
	for(int i=n;i>=1;--i)hr[i]=hr[i+1]*base+s[i]-'a'+base;
	int cnt=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			if(gh(i,j)==ghr(i,j))cnt++;
	cout<<cnt<<'\n';
	int res=1;
	int l=1,r=(n+1)/2;
	while(l+1!=r)
	{
		int mid=(l+r)>>1;
		if(check(2*mid+1))l=mid;
		else r=mid;
	}
	res=max(2*l+1,res);
	l=1,r=(n+1)/2;
		while(l+1!=r)
	{
		int mid=(l+r)>>1;
		if(check(2*mid))l=mid;
		else r=mid;
	}
	res=max(2*l,res);
	for(int i=res;i<=n;++i)
	{
		if(gh(i-res+1,i)==ghr(i-res+1,i))
		{
			for(int j=i-res+1;j<=i;++j)cout<<s[j];
			cout<<'\n';
			return;
		}
	}
}
int main()
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