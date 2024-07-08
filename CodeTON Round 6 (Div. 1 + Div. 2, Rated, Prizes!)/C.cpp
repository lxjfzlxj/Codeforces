# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
long long gcd(long long x,long long y) {return y?gcd(y,x%y):x;}
void _() {
	long long a,b,g;
	scanf("%lld%lld",&a,&b);
	g=gcd(a+b,b);
	printf("%lld/%lld\n",(a+b)/g,b/g);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

