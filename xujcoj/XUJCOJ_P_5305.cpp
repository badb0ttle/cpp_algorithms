/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
/*英文月份缩写：—月份= Jan，二月份= Feb，三月份=Mar，四月份= Apr，五月份=May，六月份=Jun，七月份=Jul，八月份= Aug，九月份= Sept，十月份= Oct，十—月份=Nov，十二月份= Dec*/
void work()
{
    map<int,string>mp;
    mp[1]="Jan.",mp[2]="Feb.",mp[3]="Mar.",mp[4]="Apr.",mp[5]="May",mp[6]="Jun.",mp[7]="Jul.",mp[8]="Aug.",mp[9]="Sept.",mp[10]="Oct.",mp[11]="Nov.",mp[12]="Dec.";
    int y,m,d;
    sc("%d.%d.%d",&y,&m,&d);
    cout<<d<<" "<<mp[m]<<", "<<y<<'\n';
}
int main()
{
// ios::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);
int _=1;
// cin >> _;
sc("%d",&_);
while (_--)work();
return 0;
}