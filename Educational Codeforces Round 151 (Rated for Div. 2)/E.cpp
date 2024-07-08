# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 1510
# define MOD 1000000007
int a[N],f[2][80][N],b[N];
void inc(int &x,int y) {(x+=y)>=MOD?x-=MOD:0;}
void _() {
	int n,m=0,k,i,j,sq,z,l,nl,ans=0;
	scanf("%d%d",&n,&k); sq=sqrt(k);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(a[i]) b[++m]=i;
	}
	f[0][sq][0]=1;
	for(i=z=1;i<=n;i++,z^=1) {
		for(j=0;j<=sq*2;j++) {
			for(l=0;l<=k;l++) if(f[z^1][j][l]) {
				nl=l+abs(j-sq);
				if(nl<=k) {
					inc(f[z][j+1-a[i]][nl],f[z^1][j][l]);
					inc(f[z][j-a[i]][nl],f[z^1][j][l]);
				}
				f[z^1][j][l]=0;
			}
		}
	}
	for(i=k;i>=0;i-=2) inc(ans,f[z^1][sq][i]);
	printf("%d",ans);
}

int main() {
	int T=1;
	// scanf("%d",&T);
	while(T--) _();
	return 0;
}