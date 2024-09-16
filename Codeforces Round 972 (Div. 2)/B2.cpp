# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define M 100010
int b[M];
void _() {
    int n,m,q,i,x;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=m;i++) scanf("%d",b+i);
    std::sort(b+1,b+m+1);
    b[0]=-1; b[m+1]=2e9;
    while(q--) {
        scanf("%d",&x);
        // if(x==b[1] || x==b[2]) puts("0");
        // else if(x<b[1]) printf("%d\n",b[1]-1);
        // else if(x>b[2]) printf("%d\n",n-b[2]);
        // else printf("%d\n",(b[2]-b[1])/2);
        // printf("ans:");
        int pos=std::lower_bound(b+1,b+m+1,x)-b;
        if(b[pos]==x) puts("0");
        else if(x<b[1]) printf("%d\n",b[1]-1);
        else if(x>b[m]) printf("%d\n",n-b[m]);
        else printf("%d\n",(b[pos]-b[pos-1])/2);
    }
}
int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}