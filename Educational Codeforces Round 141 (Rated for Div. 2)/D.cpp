# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 310
# define MOD 998244353
int a[N],f[N][N*N<<1];
void inc(int &x,int y) {(x+=y)>=MOD?x-=MOD:0;}
void _() {
	int n,i,j,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	f[2][a[2]+90000]=1;
	for(i=2;i<n;i++) {
		for(j=-90000;j<=90000;j++) if(f[i][j+90000]) {
			if(j) {
				inc(f[i+1][a[i+1]-j+90000],f[i][j+90000]);
				inc(f[i+1][a[i+1]+j+90000],f[i][j+90000]);
			} else {
				inc(f[i+1][a[i+1]+90000],f[i][j+90000]);
			}
		}
	}
	for(j=0;j<=180000;j++) inc(ans,f[n][j]);
	printf("%d",ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

