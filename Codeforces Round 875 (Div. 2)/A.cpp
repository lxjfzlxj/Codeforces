# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
int a[N];
void _() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) printf("%d ",n+1-a[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

