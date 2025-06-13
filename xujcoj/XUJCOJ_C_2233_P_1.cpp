/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long//一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define pair<int,int> PII
#define debug(x) cout<<#x<<'='<<x<<'\n'
int x,y;
/*问题描述在满二叉树中，由正整数1−n1−n组成了一棵无限大的二叉树，
其中1是根节点。1从任意一个点到根节点都有一条唯一的简单路径，
比如从1010到根节点的路径是(10,5,2,1)(10,5,2,1)，从4到根节点的路径是
(4,2,1)(4,2,1)。对于两个节点x和y到根节点的简单路径，必然在从某个节点开始相遇。
输入描述
输入两个正整数
x和y，这两个正整数都不大于1000。
输出描述在一行中输出开始相遇的节点编号。样例输入10 4样例输出2*/
int ans=0;
int d(int x,int y)
{
    if(x>y)return d(x/2,y);
    else if(x==y)return x;
    else return d(x,y/2);
}
void work()
{
    cin>>x>>y;
    
    cout<<d(x,y)<<'\n';
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