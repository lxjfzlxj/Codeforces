# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,m,i,x;
	long long s1=0,s2=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		s1+=x;
	}
	for(i=1;i<=m;i++) {
		scanf("%d",&x);
		s2+=x;
	}
	puts(s1==s2?"Draw":(s1>s2?"Tsondu":"Tenzing"));
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}