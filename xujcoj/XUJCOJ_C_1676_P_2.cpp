/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
#define PII pair<int, int>
#define debug(x) cout << #x << '=' << x << '\n'
int n;
const int mx = 201;
int f[mx], m[mx];
vector<int>b;
/*1 2 3 4 5 6 7 8*/
/*3 2 5 4 1 7 6 8*/
void g(int fl,int fr,int ml,int mr)//前序遍历的区间和中序遍历的区间
{
    if (fl > fr || ml > mr) return;//终止条件
    int pos;
    for (int i = ml; i <= mr; ++i)//遍历中序找到根节点
    {
        if (m[i] == f[fl])
        {
            pos=i;
            break;
        }
    }
    int l=pos-ml;//3 2 5 4 1 7 6 8，比如pos=2,那么我们左子树的大小就是pos-ml
    g(fl+1,fl+l,ml,pos-1);//你的当前节点的root是fl,那左子树的root不就是fl+1
    g(fl+l+1,fr,pos+1,mr);//右子树的起点在哪?在前序遍历的左子树走完之后的下一个就是右子树的根节点
    b.push_back(f[fl]);//最后输出根节点，后序遍历左右中
}
void work()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> f[i];
    for (int i = 1; i <= n; ++i)
        cin >> m[i];
    g(1,n,1,n);
    for(int i=0;i<b.size();++i)
    {
        if(i)cout<<' ';
        cout<<b[i];
    }
    cout<<'\n';
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