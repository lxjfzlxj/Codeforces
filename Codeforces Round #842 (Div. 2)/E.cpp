# include <bits/stdc++.h>
# define N 1000010
int MOD,fac[N*3],ifac[N*3];
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
void _() {
	int n,i,s1,s2,s3,sum=0,cni;
	scanf("%d%d",&n,&MOD);
	fac[0]=1;
	for(i=1;i<=n*3;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n*3]=qpow(fac[n*3],MOD-2);
	for(i=n*3-1;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
	s1=(0ll+fac[n*2]*2-fac[n]+MOD)%MOD;
	for(i=0;i<=n;i++) {
		cni=1ll*fac[n]*ifac[i]%MOD*ifac[n-i]%MOD;
		sum=(1ll*cni*cni%MOD*cni%MOD*cni%MOD*fac[i]%MOD*fac[n-i]%MOD*fac[n-i]%MOD*fac[n+i]+sum)%MOD; 
	}
	s2=(1ll*fac[2*n]*ifac[n]%MOD*fac[n*2]*2%MOD-sum+MOD)%MOD;
	s3=(fac[n*3]-s2+MOD)%MOD;
	printf("%d",(3ll*s3+2ll*(s2-s1+MOD)+(s1-1+MOD))%MOD);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

