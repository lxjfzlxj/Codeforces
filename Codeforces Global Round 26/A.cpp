# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 60
int a[N];
//char ans[N];
void _() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	if(a[1]==a[n]) puts("NO");
	else {
		puts("YES");
		if(a[2]!=a[n]) {
			putchar('R');
			for(i=2;i<=n;i++) putchar('B');
		} else {
			for(i=1;i<n;i++) putchar('R');
			putchar('B');
		}
		puts("");
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

