# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 310
int a[N],b[N][N],lim[N];
struct point{
    int x,y;
    point() {}
    point(int x,int y) {
        this->x=x; this->y=y;
    }
};
std::queue<point> q;
void _() {
    int l,n,m,i,j,k;
    scanf("%d%d%d",&l,&n,&m);
    for(i=1;i<=l;i++) scanf("%d",a+i);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) scanf("%d",b[i]+j);
    }
    while(!q.empty()) q.pop();
    // q.push(point(1,1));
    for(k=l;k>=1;k--) {
        // printf("%d:\n",k);
        for(j=0;j<=m;j++) lim[j]=-2e9;
        while(!q.empty()) {
            point pt=q.front(); q.pop();
            lim[pt.y-1]=std::max(lim[pt.y-1],pt.x);
        }
        for(j=m-1;j>=0;j--) lim[j]=std::max(lim[j],lim[j+1]);
        for(i=1;i<=n;i++) {
            for(j=1;j<=m;j++) {
                if(i>=lim[j] && b[i][j]==a[k]) q.push(point(i,j));
            }
        }
    }
    puts(q.empty()?"N":"T");
}
int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}