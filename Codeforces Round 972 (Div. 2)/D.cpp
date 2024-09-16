# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int n,a[N],b[N],ga[N][20],gb[N][20],lg2[N];
int querya(int l,int r) {
    int k=lg2[r-l+1];
    return std::__gcd(ga[l][k],ga[r-(1<<k)+1][k]);
}
int queryb(int l,int r) {
    int k=lg2[r-l+1];
    return std::__gcd(gb[l][k],gb[r-(1<<k)+1][k]);
}
struct method{
    int l,r,num,val;
    method() {}
    method(int l,int r,int num) {this->l=l; this->r=r; this->num=num;}
    void calc() {
        int vala=queryb(l,r),valb=querya(l,r);
        if(l>1) {
            vala=std::__gcd(vala,querya(1,l-1));
            valb=std::__gcd(valb,queryb(1,l-1));
        }
        if(r<n) {
            vala=std::__gcd(vala,querya(r+1,n));
            valb=std::__gcd(valb,queryb(r+1,n));
        }
        val=vala+valb;
    }
};
std::vector<method> me;
void _() {
    int i,j,g,l,r,mid,siz,mx=0;
    long long ans=0;
    std::vector<int> v;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",a+i), ga[i][0]=a[i];
    for(i=1;i<=n;i++) scanf("%d",b+i), gb[i][0]=b[i];
    for(i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    for(j=1;j<=lg2[n];j++) {
        for(i=1;i+(1<<j)-1<=n;i++) {
            ga[i][j]=std::__gcd(ga[i][j-1],ga[i+(1<<j-1)][j-1]);
            gb[i][j]=std::__gcd(gb[i][j-1],gb[i+(1<<j-1)][j-1]);
        }
    }
    me.clear();
    for(i=1;i<=n;i++) {
        v.clear();
        for(j=i;j<=n;) {
            v.push_back(j);
            g=querya(i,j);
            l=j; r=n;
            while(l<r) {
                mid=l+r+1>>1;
                if(querya(i,mid)==g) l=mid;
                else r=mid-1;
            }
            j=l+1;
        }
        for(j=n;j>=i+1;) {
            g=querya(j,n);
            l=i+1; r=j;
            while(l<r) {
                mid=l+r>>1;
                if(querya(mid,n)==g) r=mid;
                else l=mid+1;
            }
            v.push_back(l-1);
            j=l-1;
        }
        for(j=i;j<=n;) {
            v.push_back(j);
            g=queryb(i,j);
            l=j; r=n;
            while(l<r) {
                mid=l+r+1>>1;
                if(queryb(i,mid)==g) l=mid;
                else r=mid-1;
            }
            j=l+1;
        }
        for(j=n;j>=i+1;) {
            g=queryb(j,n);
            l=i+1; r=j;
            while(l<r) {
                mid=l+r>>1;
                if(queryb(mid,n)==g) r=mid;
                else l=mid+1;
            }
            v.push_back(l-1);
            j=l-1;
        }
        v.push_back(n);
        std::sort(v.begin(),v.end());
        auto it=std::unique(v.begin(),v.end());
        v.erase(it,v.end());
        v.push_back(n+1);
        for(j=0,siz=v.size();j<siz-1;j++) me.push_back(method(i,v[j],v[j+1]-v[j]));
    }
    for(auto &met:me) {
        met.calc();
        mx=std::max(mx,met.val);
    }
    for(auto &met:me) {
        if(met.val==mx) ans+=met.num;
    }
    printf("%d %lld\n",mx,ans);
}
int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}