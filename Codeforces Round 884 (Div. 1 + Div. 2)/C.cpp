# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N];
long long f[N];
void _() {
	int n,i;
	long long ans=-9e18,now=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		ans=std::max(ans,1ll*a[i]);
	}
	if(ans<=0) report("%lld\n",ans);
	for(i=1;i<=n;i+=2) {
		if(a[i]>0) now+=a[i];
	}
	ans=std::max(ans,now);
	for(i=2,now=0;i<=n;i+=2) {
		if(a[i]>0) now+=a[i];
	}
	ans=std::max(ans,now);
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}