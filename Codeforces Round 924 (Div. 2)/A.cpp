# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b) std::swap(a,b);
	if(a%2 && b%2 || b%2==0 && a%2 && b/2==a) puts("No");
	else puts("Yes"); 
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

