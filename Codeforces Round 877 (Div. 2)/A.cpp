# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,i,x,mn=2e9,mx=-2e9;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		if(x<mn) mn=x;
		if(x>mx) mx=x;
	}
	printf("%d\n",mn<0?mn:mx);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

