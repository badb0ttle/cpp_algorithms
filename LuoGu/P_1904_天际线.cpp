/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
struct node
{
    int l, r, h;
};
std::vector<node> X;
bool cmp(node a, node b)
{
    return a.l < b.l;
}
int l, r, h;
void work()
{
    while (std::cin >> l >> r >> h)
    {
        X.push_back({l, r, h});
    }
    sort(begin(X), end(X), cmp);
    int tl=X[0].l,tr=X[0].r;
    for(int i=0;i<X.size();++i)
    {
        std::cout<<X[i].h;
        if(X[i].l>=tr)
        {
            std::cout<<X[i].l-tr<<' ';
            tr=std::max(tr,X[i].r);
        }
        else
        {
            std::cout<<tr-tl<<' '<<X[i].h<<' ';
            tl=
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    // std::cin>>_;
    while (_--)
        work();
    return 0;
}