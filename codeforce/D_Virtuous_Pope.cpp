    /*blank*/
    #include <bits/stdc++.h>

    using i64 = long long;
    const int mx=1e5+1;
    struct p
    {
        int a,b;
    }dx[mx],dy[mx],dz[mx];
    int n,bx,by,bz,difx[mx*4],dify[mx*4],difz[mx*4];
    std::vector<int>X,Y,Z;
    int getidx(int x,std::vector<int>&V)
    {
        return std::lower_bound(begin(V),end(V),x)-begin(V);
    }
    void work()
    {
    std::cin>>n>>bx>>by>>bz;
    for(int i=1;i<=n;++i)
    {
        int x1,y1,z1,x2,y2,z2;
        std::cin>>x1>>y1>>z1>>x2>>y2>>z2;
            dx[i].a=std::min(x1,x2),dx[i].b=std::max(x1,x2);
            dy[i].a=std::min(y1,y2),dy[i].b=std::max(y1,y2);
            dz[i].a=std::min(z1,z2),dz[i].b=std::max(z1,z2);
    }
    for(int i=1;i<=n;++i)
    {
            X.push_back(dx[i].a),X.push_back(dx[i].b);
            Y.push_back(dy[i].a),Y.push_back(dy[i].b);
            Z.push_back(dz[i].a),Z.push_back(dz[i].b);
    }
    sort(begin(X),end(X));
    sort(begin(Y),end(Y));
    sort(begin(Z),end(Z));
    X.erase(unique(begin(X),end(X)),end(X));
    Y.erase(unique(begin(Y),end(Y)),end(Y));
    Z.erase(unique(begin(Z),end(Z)),end(Z));
    for(int i=1;i<=n;++i)
    {
        int l=getidx(std::min(dx[i].a,dx[i].b),X);
        int r=getidx(std::max(dx[i].a,dx[i].b),X);
        difx[l]++;
        difx[r+1]--;
    }
    for(int i=1;i<=n;++i)
    {
        int l=getidx(std::min(dy[i].a,dy[i].b),Y);
        int r=getidx(std::max(dy[i].a,dy[i].b),Y);
        dify[l]++;
        dify[r+1]--;
    }
    for(int i=1;i<=n;++i)
    {
        int l=getidx(std::min(dz[i].a,dz[i].b),Z);
        int r=getidx(std::max(dz[i].a,dz[i].b),Z);
        difz[l]++;
        difz[r+1]--;
    }
    int ans=-1;
    for(int i=0;i<X.size();++i)
    {
        if(i)difx[i]+=difx[i-1];
        ans=std::max(difx[i],ans);
    }
    for(int i=0;i<Y.size();++i)
    {
        if(i)dify[i]+=dify[i-1];
        ans=std::max(dify[i],ans);
    }
    for(int i=0;i<Z.size();++i)
    {
        if(i)difz[i]+=difz[i-1];
        ans=std::max(difz[i],ans);
    }
    std::cout<<ans<<'\n';
    }
    int main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int _=1;
        //std::cin>>_;
        while(_--)work();
        return 0;
    }