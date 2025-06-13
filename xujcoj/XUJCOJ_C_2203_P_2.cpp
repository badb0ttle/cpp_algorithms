/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
vector<int>a={1,2,3,4,5,6,7,8,9};
void work()
{
    do
    {
        int x=100*a[0]+10*a[1]+a[2];
        int y=100*a[3]+10*a[4]+a[5];
        int z=100*a[6]+10*a[7]+a[8];
        if(x*6==y*3&&x*6==z*2)
        {
            cout<<x<<' '<<y<<' '<<z<<'\n';
        }
    }while(next_permutation(a.begin(),a.end()));
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