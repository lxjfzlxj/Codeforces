# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
long long f[N],g[N];
int a[N];
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
	for(i=1;i<=n;i++) {
		g[i]=g[i-1]+a[i];
		f[i]=std::max(-g[i],std::max(f[i-1]+a[i],myabs(f[i-1]+a[i])));
	}
	printf("%lld\n",f[n]);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

