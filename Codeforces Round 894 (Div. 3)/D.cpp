# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	long long n,x;
	scanf("%lld",&n);
	x=sqrt(n*2);
	while(1ll*x*(x+1)/2<=n) x++;
	printf("%lld\n",x+(n-1ll*x*(x-1)/2));
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

