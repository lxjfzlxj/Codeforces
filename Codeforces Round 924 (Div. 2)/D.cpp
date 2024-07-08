# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int n,b,x,a[N];
long long calc(int mid) {
	int i;
	long long ans=0;
	for(i=1;i<=n;i++) {
		ans+=1ll*a[i]*a[i]-1ll*(a[i]%mid)*(a[i]/mid+1)*(a[i]/mid+1)-1ll*(mid-a[i]%mid)*(a[i]/mid)*(a[i]/mid);
	}
	return ans/2*b-1ll*(mid-1)*x;
}
void _() {
	int i,l,r=0,mx=0,mid;
	scanf("%d%d%d",&n,&b,&x);
	for(i=1;i<=n;i++) scanf("%d",a+i), mx=std::max(mx,a[i]);
	if(r==1) report("0\n");
	r=mx-1; l=1;
	while(l<r) {
		mid=l+r>>1;
		if(calc(mid+1)-calc(mid)<0) r=mid;
		else l=mid+1;
	}
	long long ans=0;
	for(i=std::max(1,l-5);i<=std::min(l+5,mx);i++) ans=std::max(ans,calc(i));
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

