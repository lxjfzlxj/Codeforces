# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int n,a[N],lb[N],q[N],head,tail;
long long sum[N],f[N];
bool check(long long mid) {
	int i,j;
	long long ans=sum[n];
	for(i=j=1;i<=n;i++) {
		while(sum[i]-sum[j-1]>mid) j++;
		lb[i]=j;
	}
	f[0]=0;
	head=1; tail=1; q[1]=0;
	for(i=1;i<=n;i++) {
		while(head<=tail && q[head]<lb[i-1]-1) head++;
		f[i]=f[q[head]]+a[i];
		while(head<=tail && f[q[tail]]>=f[i]) tail--;
		q[++tail]=i;
	}
	for(i=1;i<=n;i++) {
//		printf("%d: %lld\n",i,f[i]);
		ans=std::min(ans,std::max(f[i],sum[n]-sum[i]));
	}
	return ans<=mid;
}
void _() {
	int i;
	long long l=0,r=0,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i), r+=a[i], l=std::max(l,1ll*a[i]), sum[i]=sum[i-1]+a[i];
	while(l<r) {
		mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
//	check(7);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

