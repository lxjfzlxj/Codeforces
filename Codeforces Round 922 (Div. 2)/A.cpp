# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int n,a[N],b[N];
void _() {
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+a[i]);
	for(i=1;i<=n;i++) printf("%d ",i);
	puts("");
	for(i=1;i<=n;i++) printf("%d ",b[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

