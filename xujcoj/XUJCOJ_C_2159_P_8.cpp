/*blank*/
#include<bits/stdc++.h>
using namespace std;
#define int long long//十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
int mp[10][10];
void swapf(int g1,int g2)
{
    int a[4][4],b[4][4];
    int f1=g1/3;int f2=g2/3;
    int l1=g1%3;int l2=g2%3;
    if(l1==0)
    {
        f1--;
        l1=3;
    }
    if(l2==0)
    {
        f2--;
        l2=3;
    }
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            a[i][j]=mp[i+3*(f1)][(l1-1)*3+j];
        }
    }
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            b[i][j]=mp[i+3*(f2)][(l2-1)*3+j];
        }
    }
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            mp[i+3*(f1)][(l1-1)*3+j]=b[i][j];
            mp[i+3*(f2)][(l2-1)*3+j]=a[i][j];
        }
    }
}
bool iscorrect()
{
    bool vis[10];
    for(int i=1;i<=9;++i)
    {
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=9;++j)
        {
            if(vis[mp[i][j]])return 0;
            vis[mp[i][j]]=1;
        }
    }
    for(int i=1;i<=9;++i)
    {
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=9;++j)
        {
            if(vis[mp[j][i]])return 0;
            vis[mp[j][i]]=1;
        }
    }
    for(int i=1;i<=9;i+=3)
    {
        for(int j=1;j<=9;j+=3)
        {
            memset(vis,0,sizeof(vis));
            for(int k=i;k<=i+2;++k)
            {
                for(int l=j;l<=j+2;++l)
                {
                    if(vis[mp[k][l]])return 0;
                    vis[mp[k][l]]=1;
                }
            }
        }
    }
    return 1;
}
void work()
{
    for(int i=1;i<=9;++i)
    {
        for(int j=1;j<=9;++j)
        {
            cin>>mp[i][j];
        }
    }
   if(iscorrect())
   {
       cout<<"YES\n";
       return;
   }
   else
   {
      for(int i=1;i<=9;++i)
      {
          for(int j=i+1;j<=9;++j)
          {
              swapf(i,j);
              if(iscorrect())
              {
                  cout<<i<<' '<<j<<'\n';
                  return;
              }
              swapf(i,j);
          }
      }
   }
    cout<<"NO\n";
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