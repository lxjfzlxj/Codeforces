# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,i;
	scanf("%d",&n);
	printf("%d ",n%2?1:1+n/2);
	for(i=2;i<=n;i++) printf("%d ",i);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

