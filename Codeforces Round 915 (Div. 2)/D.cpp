# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 1000010
int a[N<<1],q[N<<1],head,tail;
void _() {
	int n,i;
	long long sum=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i), a[n+i]=a[i];
	head=1; tail=0;
	for(i=1;i<=n;i++) {
		while(head<=tail && a[q[tail]]>a[i]) tail--;
		q[++tail]=i;
	}
	for(i=head+1;i<=tail;i++) sum+=1ll*(q[i]-q[i-1])*a[q[i]];
	ans=sum+n;
	for(i=n+1;i<=n*2;i++) {
		while(head<=tail && q[head]<=i-n) {
			sum-=1ll*(q[head+1]-q[head])*a[q[head+1]];
			head++;
		}
		while(head<=tail && a[q[tail]]>a[i]) {
			if(head<tail) sum-=1ll*(q[tail]-q[tail-1])*a[q[tail]];
			tail--;
		}
		q[++tail]=i;
		if(head<tail) sum+=1ll*(q[tail]-q[tail-1])*a[q[tail]];
		ans=std::max(ans,sum+n);
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

