# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
int a[N],d[N];
int abs(int x) {return x>=0?x:-x;}

void _() {
	int n,k,i,ans=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<n;i++) d[i]=abs(a[i+1]-a[i]);
	std::sort(d+1,d+n);
	for(i=1;i<=n-k;i++) ans+=d[i];
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

