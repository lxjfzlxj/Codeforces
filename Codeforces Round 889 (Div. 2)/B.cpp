# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	long long n;
	int i;
	scanf("%lld",&n);
	for(i=1;n%i==0;i++);
	printf("%d\n",i-1);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

