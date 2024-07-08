# include <bits/stdc++.h>
# define N 200010
int a[N],sum[N],buc[N<<1];
void _() {
	int n,i,j;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n*2;i++) buc[i]=0;
	buc[0]=1;
	for(i=1;i<=n;i++) {
		sum[i]=sum[i-1]^a[i];
		ans+=buc[sum[i]];
		for(j=1;j*j<=n*2;j++) {
			if((sum[i]^(j*j))<=n*2) ans+=buc[sum[i]^(j*j)];
		}
		buc[sum[i]]++;
	}
	printf("%lld\n",1ll*n*(n+1)/2-ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

