# include <bits/stdc++.h>
# define N 110
int a[N<<1];
void _() {
	int n,m,i;
	long long ans=0;
	scanf("%d%d",&n,&m); m+=n;
	for(i=1;i<=m;i++) scanf("%d",a+i);
	std::sort(a+1,a+m);
	for(i=m-n+1;i<=m;i++) ans+=a[i];
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

