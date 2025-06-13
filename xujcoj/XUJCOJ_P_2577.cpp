/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
const int mx=1e5+1;
int n;
void work()
{
    cin>>n;
    ll a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a, a + n);
	if (n % 2 != 0)
	{
		ll b = 0, c = 0;
		int mid = n / 2 ;
		for (int j = 0; j < n; j++)
		{
			b+=abs(a[j] - a[mid]);
		}
		cout << b;
	}
    else
	{
		ll b = 0, c = 0;
		ll m1 = n / 2;
		ll m2 = n / 2 + 1;
		for (int j = 0; j < n; j++)
		{
				b += abs(a[j] - a[m1]);
				c += abs(a[j] - a[m2]);
		}
		cout << min(b, c);
	}
}
int main()
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