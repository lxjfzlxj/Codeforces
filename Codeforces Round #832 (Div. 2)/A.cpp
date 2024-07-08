# include <bits/stdc++.h>

void _() {
	int n,i,x;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		ans+=x;
	}
	printf("%lld\n",ans>=0?ans:-ans);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

