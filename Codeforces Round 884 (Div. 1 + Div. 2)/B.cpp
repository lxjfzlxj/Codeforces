# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,i,m;
	scanf("%d",&n);
	if(n==1) puts("1");
	else if(n==2) puts("1 2");
	else {
		m=3;
		for(i=1;i<=n;i++) {
			if(i==1) printf("2 ");
			else if(i==n) puts("3");
			else if(i==(n+1)/2) printf("1 ");
			else printf("%d ",++m);
		}
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}