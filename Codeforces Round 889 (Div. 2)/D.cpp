# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int a[N];
long long sum[N];
std::bitset<N<<1> f[2];
void _() {
	int n,i,j,z;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	f[0][0]=1;
	for(i=z=1;i<=n;i++,z^=1) {
		f[z]=f[z^1]|(f[z^1]<<a[i]);
		if(f[z][i-1]) ans=std::max(ans,sum[i]-i+1);
		if(i==n) {
			for(j=n-1;j<=n*2 && !f[z][j];j++);
			if(j<=n*2) ans=std::max(ans,sum[n]-j);
		}
		f[z][i-1]=0;
	}
	printf("%lld",ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

