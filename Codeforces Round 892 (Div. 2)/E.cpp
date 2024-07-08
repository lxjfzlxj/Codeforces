# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 3010
int a[N];
long long f[N][N];
void _() {
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=0;i<=n;i++) {
		for(j=0;j<=n;j++) f[i][j]=-1e18;
	}
	f[0][0]=0;
	for(i=1;i<=n;i++) {
		f[i][j]=f[i-1][j];
		for(j=1;j<=k && j<=i;j++) {
			f[i][j]=std::max(f[i][j],f[])
		}
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

