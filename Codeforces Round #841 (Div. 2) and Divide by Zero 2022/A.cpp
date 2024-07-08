# include <bits/stdc++.h>

void _() {
	int n,i,x;
	long long ans=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		ans*=x;
	}
	printf("%lld\n",(ans+n-1)*2022);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

