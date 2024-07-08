# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 2010
# define MOD 1000000007
int n,m,k,fac[N<<1],ifac[N<<1];
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
int C(int n,int m) {
	if(n<0 || m<0 || n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int calc(int low) {return (C(n+m,n)-C(n+m,low+m-1)+MOD)%MOD;}
void _() {
	scanf("%d%d%d",&n,&m,&k);
	if(k>n || k>m) report("0\n");
	printf("%d\n",(calc(k-m)-calc(k-m+1)+MOD)%MOD);
}

int main() {
	int T=1,i;
	scanf("%d",&T);
	fac[0]=1;
	for(i=1;i<=4000;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[4000]=qpow(fac[4000],MOD-2);
	for(i=3999;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
	while(T--) _();
	return 0;
}

