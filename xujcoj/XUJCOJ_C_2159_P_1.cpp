/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
/*+------+
|A /\  |
| /  \ |
| \  / |
|  \/ A|
+------+ */
void work()
{
    char a;
    cin >> a;
    cout<<"+------+\n";
    cout<<"|"<<a<<" /\\  |\n";
    cout<<"| /  \\ |\n";
    cout<<"| \\  / |\n";
    cout<<"|  \\/ "<<a<<"|\n";
    cout<<"+------+\n";
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