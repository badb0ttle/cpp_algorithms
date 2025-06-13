/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int gf(int x, int y, int n) {
    return y / n - (x - 1) / n;
}
void work()
{
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    int a_b=lcm(a,b),b_c=lcm(b,c),c_a=lcm(c,a),a_b_c=lcm(a_b,c);    
    int n_ab=gf(x,y,a_b),n_bc=gf(x,y,b_c),n_ca=gf(x,y,c_a),n_abc=gf(x,y,a_b_c);
    int ans=n_ab+n_bc+n_ca-3*n_abc;
    cout<<ans<<'\n';
}
signed main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int _=1;
cin >> _;
//sc("%d",&_);
while (_--)work();
return 0;
}