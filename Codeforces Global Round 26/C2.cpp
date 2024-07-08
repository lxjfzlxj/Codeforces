# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
# define MOD 998244353
long long f[N],g[N];
int a[N],ff[N],gg[N];
long long myabs(long long x) {
	return x>=0?x:-x;
}
void _() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
	}
	f[0]=g[0]=0;
	
	ff[0]=gg[0]=1;
	bool flag=false;
	for(i=1;i<=n;i++) {
		g[i]=g[i-1]+a[i];
		f[i]=std::max(-g[i],std::max(f[i-1]+a[i],myabs(f[i-1]+a[i])));
		if(g[i]<0 && !flag) {
			flag=true;
			ff[i]=ff[i-1];
			gg[i]=gg[i-1];
			continue;
		}
		if(!flag) {
			ff[i]=ff[i-1]*2%MOD;
			gg[i]=gg[i-1]*2%MOD;
		} else {
			gg[i]=gg[i-1];
			if(g[i]>=0) gg[i]=(gg[i]+gg[i-1])%MOD;
			ff[i]=0;
			if(-g[i]==f[i]) ff[i]=(ff[i]+gg[i])%MOD;
			if(f[i-1]+a[i]==f[i]) ff[i]=(ff[i]+ff[i-1])%MOD;
			if(myabs(f[i-1]+a[i])==f[i]) ff[i]=(ff[i]+ff[i-1])%MOD;
		}
//		printf("%d %d\n",ff[i],gg[i]);
	}
	printf("%d\n",ff[n]);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

