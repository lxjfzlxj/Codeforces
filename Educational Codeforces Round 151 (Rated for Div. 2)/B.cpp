# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
    int xa,ya,xb,yb,xc,yc,ans=0;
    scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
    xb-=xa; yb-=ya; xc-=xa; yc-=ya;
    if(xb<0 && xc<0) ans+=std::min(-xb,-xc);
    if(xb>0 && xc>0) ans+=std::min(xb,xc);
    if(yb<0 && yc<0) ans+=std::min(-yb,-yc);
    if(yb>0 && yc>0) ans+=std::min(yb,yc);
    printf("%d\n",ans+1);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}