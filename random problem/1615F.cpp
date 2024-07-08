# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 2010
# define MOD 1000000007
char s[N],t[N];
int f[N][N<<1],g[N][N<<1];
void inc(int &x,int y) {(x+=y)>=MOD?x-=MOD:0;}
void _() {
	int n,i,j,k1,k2;
	scanf("%d%s%s",&n,s+1,t+1);
	for(i=1;i<=n;i++) if(i&1) {
		if(s[i]!='?') s[i]=!(s[i]-'0')+'0';
		if(t[i]!='?') t[i]=!(t[i]-'0')+'0';
	}
	for(i=0;i<=n;i++) {
		for(j=0;j<=n*2;j++) f[i][j]=g[i][j]=0;
	}
	f[0][n]=0; g[0][n]=1;
	for(i=1;i<=n;i++) {
		for(j=-i+1;j<=i-1;j++) if(g[i-1][j+n] || f[i-1][j+n]) {
			for(k1=(s[i]=='?'?0:s[i]-'0');k1<=(s[i]=='?'?1:s[i]-'0');k1++) {
				for(k2=(t[i]=='?'?0:t[i]-'0');k2<=(t[i]=='?'?1:t[i]-'0');k2++) {
					inc(g[i][j+n+k1-k2],g[i-1][j+n]);
					inc(f[i][j+n+k1-k2],(1ll*abs(j+k1-k2)*g[i-1][j+n]+f[i-1][j+n])%MOD);
				}
			}
		}
	}
	printf("%d\n",f[n][n]);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

