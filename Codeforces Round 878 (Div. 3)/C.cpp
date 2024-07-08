# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N];
void _() {
	int n,k,q,i,j;
	long long ans=0;
	scanf("%d%d%d",&n,&k,&q);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) if(a[i]<=q) {
		for(j=i;j<=n && a[j]<=q;j++);
		if(j-i>=k) ans+=1ll*(j-i-k+1)*(j-i-k+2)/2;
		i=j-1;
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

