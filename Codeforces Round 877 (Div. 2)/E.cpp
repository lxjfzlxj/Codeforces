# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define MOD 1000000007
# define N 200010
int inv[N];
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
void _() {
	int n,m,k,i,vx,vy,dt,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%*d");
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	vx=1; vy=qpow(k-1,m); dt=qpow(k-1,MOD-2); 
	for(i=0;i<n;i++) {
		ans=(1ll*vx*vy+ans)%MOD;
		vx=1ll*vx*(m-i)%MOD;
		vy=1ll*vy*dt%MOD*inv[i+1]%MOD;
	}
	printf("%d\n",(qpow(k,m)-ans+MOD)%MOD);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

