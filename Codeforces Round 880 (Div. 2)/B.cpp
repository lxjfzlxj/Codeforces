# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,k,g;
	long long ans;
	scanf("%d%d%d",&n,&k,&g);
	ans=1ll*n*((g+1)/2-1);
	if(ans%g) ans=ans/g*g;
	if(ans>1ll*k*g) ans=1ll*k*g;
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

