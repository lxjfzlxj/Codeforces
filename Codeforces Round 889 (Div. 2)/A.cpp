# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,i,x,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		if(x==i) ans++;
	}
	printf("%d\n",ans+1>>1);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

