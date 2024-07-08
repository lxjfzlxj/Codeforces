# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
# define MOD 1000000007
int n,fac[N],ifac[N],p2[N];
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
int C(int n,int m) {
	if(n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int max(int x,int y) {return x>y?x:y;}
int calc1(int ii,int jj,int x,int y) {
	int ans=1ll*C(x-1,ii-1)*C(y-x-1,jj-ii-1)%MOD*p2[max(n-y-1,0)]%MOD;
	if(ii==x && jj==y) ans=(ans-1+MOD)%MOD;
	return ans;
}
int calc2(int ii,int jj,int x,int y) {
	if(n-jj<x-ii) return 0;
	return 1ll*C(x-1,ii-1)*C(y-x-1,n-jj-(x-ii))%MOD*p2[n-y-1]%MOD;
}
void _() {
	int ii,jj,x,y,ans;
	scanf("%d%d%d%d%d",&n,&ii,&jj,&x,&y);
	if(x<y) ans=calc1(ii,jj,x,y);
	else ans=calc1(n-jj+1,n-ii+1,y,x);
	if(x<n && y<n) {
		if(x<y) ans=(ans+calc2(ii,jj,x,y))%MOD;
		else ans=(ans+calc2(n-jj+1,n-ii+1,y,x))%MOD;
	}
	printf("%d\n",ans);
}

int main() {
	int T=1,i;
	scanf("%d",&T);
	fac[0]=1;
	for(i=1;i<=100;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[100]=qpow(fac[100],MOD-2);
	for(i=99;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
	p2[0]=1;
	for(i=1;i<=100;i++) p2[i]=p2[i-1]*2%MOD;
	while(T--) _();
	return 0;
}

