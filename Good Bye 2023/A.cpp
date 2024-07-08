# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,k,i,x;
	long long mul=1;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&x), mul*=x;
	if(2023%mul) puts("NO");
	else {
		puts("YES");
		for(i=1;i<k;i++) printf("1 ");
		printf("%d\n",2023/mul);
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

