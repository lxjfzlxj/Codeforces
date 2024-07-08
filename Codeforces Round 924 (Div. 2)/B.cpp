# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N];
void _() {
	int n,n0,i,j,ans=0;
	scanf("%d",&n); n0=n;
	for(i=1;i<=n;i++) scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	n=std::unique(a+1,a+n+1)-a-1;
	for(i=j=1;i<=n;i++) {
		
		while(a[i]-a[j]>=n0) j++;
//		printf("%d %d\n",a[i],j);
		ans=std::max(ans,i-j+1);
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

