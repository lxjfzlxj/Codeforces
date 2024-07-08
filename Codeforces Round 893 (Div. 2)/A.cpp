# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c&1) puts(b>a?"Second":"First");
	else puts(b>=a?"Second":"First");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

