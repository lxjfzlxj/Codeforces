# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
    int i,n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    if(x!=1) {
        puts("YES");
        printf("%d\n",n);
        for(i=1;i<=n;i++) printf("1 "); puts("");
    } else {
        if(k==1) puts("NO");
        else if(k==2) {
            if(n&1) puts("NO");
            else {
                puts("YES");
                printf("%d\n",n/2);
                for(i=1;i<=n/2;i++) printf("2 "); puts("");
            }
        }
        else {
            if(n<2) puts("NO");
            else {
                puts("YES");
                printf("%d\n",n/2);
                for(i=1;i<=n/2;i++) printf("%d ",(i==1 && n%2)?3:2); puts("");
            }
        }
    }
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}