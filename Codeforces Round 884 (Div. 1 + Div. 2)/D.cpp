# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,i,m;
	scanf("%d",&n);
	for(m=1;n%m==0;m++);
	for(i=1;i<=n;i++) putchar('a'+(i%m));
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}