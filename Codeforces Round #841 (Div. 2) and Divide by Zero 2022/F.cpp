# include <bits/stdc++.h>
# define MOD 998244353
# define N 60
int n,k,y[N],C[N][N];
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
int calc(int x) {
	int i,ans=0,j,ss;
	for(i=1;i<=n+2;i++) {
		ss=1;
		for(j=1;j<=n+2;j++) if(i!=j) {
			ss=1ll*ss*(x-j+MOD)%MOD*qpow(i-j+MOD,MOD-2)%MOD;
		}
		ans=(1ll*ss*y[i]+ans)%MOD;
	}
	return ans;
}
void _() {
	int i,j,p,q,ans=0;
	scanf("%d%d",&n,&k);
	C[0][0]=1;
	for(i=1;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n+2 && j<=k;j++) {
			y[j]=0;
			for(p=0;p<i;p++) {
				for(q=p+1;q<=n-i;q++) {
					y[j]=(1ll*C[i-1][p]*qpow(j-1,p)%MOD*qpow(k-j+1,i-1-p)%MOD
							 *C[n-i][q]%MOD*qpow(k-j,q)%MOD*qpow(j,n-i-q)+y[j])%MOD;
				}
			}
			y[j]=(1ll*y[j]*j+y[j-1])%MOD;
		}
		if(k<=n+2) ans=(ans+y[k])%MOD;
		else ans=(ans+calc(k))%MOD;
	}
	printf("%d",ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

