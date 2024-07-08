# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,m,i,x,fmin,mn=2e9,smin,smn=2e9;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&m);
		fmin=smin=2e9;
		while(m--) {
			scanf("%d",&x);
			if(x<fmin) smin=fmin, fmin=x;
			else if(x<smin) smin=x;
			mn=std::min(mn,x);
		}
		smn=std::min(smn,smin);
		ans+=smin;
	}
	printf("%lld\n",ans-smn+mn);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

