# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,k,i,p;
	scanf("%d%d",&n,&k);
	p=log2(n)+1;
	printf("%d\n",k>=p?n+1:(1<<k));
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

