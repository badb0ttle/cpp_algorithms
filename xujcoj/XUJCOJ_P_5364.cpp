    /*blank*/
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long//一时偷懒不收敛，乱开ll终遭谴
    #define sc scanf
    #define pr printf
    #define PII pair<int,int>
    #define debug(x) cout<<#x<<'='<<x<<'\n'
    const int mx=101;
    vector<PII>rk;
    struct node
    {
        int a,b,c,d,sum;
    };
    bool cmp(node a,node b)
    {
        return a.sum<b.sum;
    }
    int n;
    vector<node>vec;
    void work()
    {
        cin>>n;
        vec.resize(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>vec[i].a>>vec[i].b>>vec[i].c>>vec[i].d;
            vec[i].sum=vec[i].a+vec[i].b+vec[i].c+vec[i].d;
        }
        sort(vec.begin()+1,vec.end(),cmp);
        for(int i=1;i<=n;++i)
        {
            cout<<vec[i].a<<' '<<vec[i].b<<' '<<vec[i].c<<' '<<vec[i].d<<'\n';
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