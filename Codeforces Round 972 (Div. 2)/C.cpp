# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 1010
char s[N][N];
int f[N][5];
void _() {
    int n,m,i,st,now,j,val,ans=0;
    char ch[10]="narek";
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(i=0;i<=n;i++) {
        for(j=0;j<5;j++) f[i][j]=-2e9;
    }
    f[0][0]=0;
    for(i=1;i<=n;i++) {
        for(st=0;st<5;st++) if(f[i-1][st]>=-1e9) {
            // printf("%d %d: %d\n",i-1,st,f[i-1][st]);
            f[i][st]=std::max(f[i][st],f[i-1][st]);
            now=st; val=f[i-1][st];
            for(j=1;j<=m;j++) {
                if(s[i][j]=='n' || s[i][j]=='a' || s[i][j]=='r' || s[i][j]=='e' || s[i][j]=='k') val--;
                if(s[i][j]==ch[now]) {
                    now=(now+1)%5;
                    if(now==0) val+=10;
                }
            }
            f[i][now]=std::max(f[i][now],val);
            // printf(" ==> %d %d (%d)\n",i,now,val);
        }
    }
    for(j=0;j<5;j++) ans=std::max(ans,f[n][j]);
    printf("%d\n",ans);
}
int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}