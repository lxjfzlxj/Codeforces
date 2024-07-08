# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 510
# define MOD 1000000007
int a[N],f[N][N];
const int i2=(MOD+1)/2;
void _() {
	int n,m,i,j,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=m+1;i++) f[i][m+1]=m+1-i;
	for(j=m;j>=1;j--) {
		f[i][i]=0;
		for(i=j-1;i>=1;i--) f[i][j]=1ll*i2*(f[i+1][j]+1+f[i][j+1])%MOD;
	}
	a[n+1]=m+1;
	for(i=1;i<=n;i++) ans=(ans+f[a[i]][a[i+1]])%MOD;
	printf("%d",ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

