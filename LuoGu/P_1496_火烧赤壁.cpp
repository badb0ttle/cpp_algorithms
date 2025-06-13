    /*blank*/
    #include <bits/stdc++.h>

    using i64 = long long;
    struct node
    {
        int a,b;
    };
    std::vector<node>N;
    int q, l, r;
    bool cmp(node a,node b)
    {
        return a.a<b.a;
    }
    void work()
    {
        std::cin>>q;
        for(int i=1;i<=q;++i)
        {
            std::cin>>l>>r;
            N.push_back({l,r});
        }
        std::sort(begin(N),end(N),cmp);
        int ans=0;
        int tl=N[0].a,tr=N[0].b;
        for(int i=1;i< N.size();++i)
        {
            if(N[i].a<tr)
            {
                tr=std::max(N[i].b,tr);
            }
            else
            {
                ans+=tr-tl;
                // std::cout<<ans<<'\n';
                tl=N[i].a;
                tr=N[i].b;
            }
        }
        ans+=tr-tl;
        std::cout<<ans<<'\n';
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