# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
int a[N];
long long sum[N],suf[N];
void _() {
	int n,i;
	long long mx=-1e18,ans,ansk,tp;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	suf[n+1]=1e18;
	for(i=n;i>=1;i--) suf[i]=std::min(suf[i+1],sum[i]);
	ans=sum[n];
	for(i=0;i<=n;i++) {
		if(sum[i]>mx) {
			mx=sum[i];
			tp=sum[n]+std::max(sum[i]-suf[i+1],0ll);
			if(tp>=ans) ans=tp, ansk=sum[i];
		}
	}
	printf("%lld\n",ansk);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}