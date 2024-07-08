# include <bits/stdc++.h>
# define N 200010
# define MOD 998244353
int a[N];
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
void _() {
	int n,i,cnt=0,c0=0,ans=0,all;
	scanf("%d",&n); all=1ll*n*(n-1)/2%MOD;
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(!a[i]) cnt++;
	}
	for(i=1;i<=cnt;i++) {
		if(!a[i]) c0++;
	}
	for(i=c0;i<cnt;i++) ans=(1ll*all*qpow(1ll*(cnt-i)*(cnt-i)%MOD,MOD-2)+ans)%MOD;
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

