/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
/*有一棵二叉树，最大深度为D，且所有叶子的深度都相同。所有结点从上
到下从左到右编号为1，2，3，…，2^D-1。在结点1处放一个小球，它会往下落。每个内部结点上
都有一个开关，初始全部关闭，当每次有小球落到一个开关上时，它的状态都会改变
。当小球到达一个内部结点时，如果该结点上的开关关闭，则往左走，否则往右走，直到走到叶子结点，如图所示。
一些小球从结点1处依次开始下落，最后一个小球将会落到哪里呢？输入叶子深度D和小球个数I，输出第I个小球最后所在的叶子编号。假设I不超过整棵树的叶子个数，D≤30。*/
void work()
{
    int n,i;
    cin>>n>>i;
    int beg=1;
    for(int j=0;j<n-1;j++)
    {
        if(i&1)beg=beg*2,i=(i+1)/2;
        else beg=beg*2+1,i=i/2;
    }
    cout<<beg<<'\n';
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